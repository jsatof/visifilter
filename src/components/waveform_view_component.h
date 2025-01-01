#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_audio_utils/juce_audio_utils.h>
#include <juce_gui_basics/juce_gui_basics.h>

class WaveformViewComponent : public juce::AudioVisualiserComponent {
public:
    WaveformViewComponent(int nChannels);

    // juce::Component overrides
    //void paint(juce::Graphics &g) override;
    void paintChannel(juce::Graphics &g, juce::Rectangle<float> bounds, const juce::Range<float> *levels, int nLevels, int nextSample) override;

private:
    int m_channels;
    std::vector<float> waveform_data;
};
