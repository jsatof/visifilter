#include <components/waveform_view_component.h>

WaveformViewComponent::WaveformViewComponent(int nChannels)
    : juce::AudioVisualiserComponent(nChannels)
    , m_channels(nChannels)
{
    setSize(1000, 200);
    setRepaintRate(30);
    setBufferSize(4096);
}

void WaveformViewComponent::paintChannel(juce::Graphics &g, juce::Rectangle<float> bounds, const juce::Range<float> *levels, int nLevels, int nextSample) {
    juce::Path wave_path = {};
    getChannelAsPath(wave_path, levels, nLevels, nextSample);
    g.setColour(juce::Colours::yellow);
    g.strokePath(wave_path, juce::PathStrokeType{ 1.f, juce::PathStrokeType::JointStyle::curved, juce::PathStrokeType::EndCapStyle::rounded });

    juce::ignoreUnused(bounds);
}
