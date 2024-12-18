#include <components/waveform_view_component.h>

WaveformViewComponent::WaveformViewComponent() {
	setSize(1000, 200);
}

void WaveformViewComponent::paint(juce::Graphics &g) {
	g.setColour(juce::Colours::brown);
}

void WaveformViewComponent::setAudioData(const juce::AudioBuffer<float> &buffer) {
	juce::ignoreUnused(buffer);
}
