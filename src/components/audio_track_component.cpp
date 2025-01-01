#include <components/audio_track_component.h>

#include <print>

AudioTrackComponent::AudioTrackComponent(const int inputChannels, const int outputChannels)
    : io_region_w(200)
    , waveform_view(2)
{
    setSize(1000, 100);
    setAudioChannels(inputChannels, outputChannels);
    format_manager.registerBasicFormats();

    track_name_label.setText("Load an audio file", juce::NotificationType::dontSendNotification);
    track_name_label.setEditable(false);
    addAndMakeVisible(track_name_label);

    load_file_button.setButtonText("Load File");
    load_file_button.onClick = [this]() { on_load_file_clicked(); };
    addAndMakeVisible(load_file_button);

    solo_button.setButtonText("S");
    solo_button.addListener(this);
    addAndMakeVisible(solo_button);

    mute_button.setButtonText("M");
    mute_button.addListener(this);
    addAndMakeVisible(mute_button);

    wave_flip_button.setButtonText("F");
    wave_flip_button.addListener(this);
    addAndMakeVisible(wave_flip_button);

    auto wf_bounds = waveform_view.getBounds();
    wf_bounds.setPosition(wf_bounds.getX() + io_region_w, wf_bounds.getY());
    waveform_view.setBounds(wf_bounds);
    waveform_view.setColours(juce::Colours::magenta, juce::Colours::green);
    addAndMakeVisible(waveform_view);
}

AudioTrackComponent::~AudioTrackComponent() {
    shutdownAudio();
}

void AudioTrackComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
    transport_source.prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void AudioTrackComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill) {
    if (reader_source.get() == nullptr) {
        bufferToFill.clearActiveBufferRegion();
        return;
    }

    transport_source.getNextAudioBlock(bufferToFill);
    //juce::AudioSourceChannelInfo audio_source = bufferToFill;
    waveform_view.pushBuffer(bufferToFill);
}

void AudioTrackComponent::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
    g.setColour(juce::Colours::black);
    g.drawRect(getBounds(), 1);

    g.setColour(juce::Colours::black);
    g.drawRect(waveform_view.getBounds(), 1);
}

void AudioTrackComponent::resized() {
    constexpr int button_w = 50, button_h = 20;
    constexpr int margin = 10;

    track_name_label.setBounds(margin + button_w,     margin + getBounds().getY(), 100, 32);
    load_file_button.setBounds(margin + button_w, 2 * margin + getBounds().getY(), 100, 32);

    solo_button.setBounds(     margin + (0 * button_w), (getHeight() + button_h) / 2, button_w, button_h);
    mute_button.setBounds(     margin + (1 * button_w), (getHeight() + button_h) / 2, button_w, button_h);
    wave_flip_button.setBounds(margin + (2 * button_w), (getHeight() + button_h) / 2, button_w, button_h);

    waveform_view.setBounds(waveform_view.getLocalBounds());
}

static void toggleButtonState(juce::Button *button) {
    if (!button) {
        return;
    }
    auto buttonDown = juce::Button::ButtonState::buttonDown;
    auto buttonUp = juce::Button::ButtonState::buttonNormal;
    const juce::Button::ButtonState new_state = (button->getState() == buttonUp) ? buttonDown : buttonUp;
    button->setState(new_state);
}

void AudioTrackComponent::buttonClicked(juce::Button *button) {
    toggleButtonState(button);
}

void AudioTrackComponent::on_load_file_clicked() {
    /*
    file_chooser = std::make_unique<juce::FileChooser>("Select an audio file.", juce::File{}, "*.wav");

    auto file_chooser_flags = juce::FileBrowserComponent::openMode | juce::FileBrowserComponent::canSelectFiles;
    file_chooser->launchAsync(file_chooser_flags, [this](const juce::FileChooser &chooser) {
            auto file = chooser.getResult();
            if (file != juce::File{}) {
                auto *reader = format_manager.createReaderFor(file);
                if (reader != nullptr) {
                    auto new_source = std::make_unique<juce::AudioFormatReaderSource>(reader, true);
                    transport_source.setSource(new_source.get(), 0, nullptr, reader->sampleRate);
                    reader_source.reset(new_source.release());
                }
            }
    });
    */

    juce::File test_file = {"res/test_loop.ogg"};
    if (!test_file.exists()) {
        std::print(stderr, "ERROR: {} doesnt exist\n", test_file.getFullPathName().toStdString());
        return;
    }

    juce::AudioFormat *found_format = format_manager.findFormatForFileExtension(test_file.getFileExtension());
    jassert(found_format);

    if (found_format->canHandleFile(test_file)) {
        std::print("STATUS: FormatManager can handle {}\n", test_file.getFullPathName().toStdString());
    } else {
        std::print(stderr, "ERROR: FormatManager cannot handle {}\n", test_file.getFullPathName().toStdString());
    }


    // This is giving nullptr for some reason
    auto *reader = format_manager.createReaderFor(test_file);
    jassert(reader != nullptr);

    auto new_source = std::make_unique<juce::AudioFormatReaderSource>(reader, true);
    transport_source.setSource(new_source.get(), 0, nullptr, reader->sampleRate);
    transport_source.setGain(0.5);
    transport_source.setLooping(true);
    transport_source.start();
    reader_source.reset(new_source.release());

}

void AudioTrackComponent::releaseResources() {
    transport_source.releaseResources();
}
