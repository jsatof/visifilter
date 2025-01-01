#pragma once

#include <juce_audio_utils/juce_audio_utils.h>
#include <juce_gui_basics/juce_gui_basics.h>

#include <components/waveform_view_component.h>

class AudioTrackComponent : public juce::AudioAppComponent, public juce::Button::Listener {
public:
    AudioTrackComponent(const int inputChannels=2, const int outputChannels=0);
    ~AudioTrackComponent();

    // overloads
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo &buffer) override;
    void releaseResources() override;

    void buttonClicked(juce::Button *button) override;
    void paint(juce::Graphics &g) override;
    void resized() override;

private:
    void on_load_file_clicked();

    const int io_region_w;

    // ui
    juce::Label track_name_label;
    juce::TextButton load_file_button;
    juce::ToggleButton solo_button;
    juce::ToggleButton mute_button;
    juce::ToggleButton wave_flip_button; // polarity flip toggle
    WaveformViewComponent waveform_view;

    // playback
    juce::AudioFormatManager format_manager;
    juce::AudioTransportSource transport_source;
    std::unique_ptr<juce::AudioFormatReaderSource> reader_source;
    std::unique_ptr<juce::FileChooser> file_chooser;
};
