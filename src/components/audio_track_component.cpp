#include <components/audio_track_component.h>

AudioTrackComponent::AudioTrackComponent()
    : io_region_w(200)
{
    setSize(1000, 100);

    track_name_label.setText("Load an audio file", juce::NotificationType::dontSendNotification);
    track_name_label.setEditable(false);
    addAndMakeVisible(track_name_label);

    load_file_button.setButtonText("Load File");
    load_file_button.onClick = on_load_file_clicked;
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
    addAndMakeVisible(waveform_view);
}

void AudioTrackComponent::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
    g.setColour(juce::Colours::black);
    g.drawRect(getBounds(), 1);

    g.setColour(juce::Colours::magenta);
    g.fillRect(waveform_view.getBounds());
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
    std::cout << ("STATUS: load file button clicked\n");
}
