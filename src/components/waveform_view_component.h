#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_gui_basics/juce_gui_basics.h>

class WaveformViewComponent : public juce::Component {
public:
	WaveformViewComponent();

	// juce::Component overrides
	void paint(juce::Graphics &g) override;

	void setAudioData(const juce::AudioBuffer<float> &buffer);

private:
	std::vector<float> waveform_data;
};
