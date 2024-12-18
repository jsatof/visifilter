#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include <components/waveform_view_component.h>

class AudioTrackComponent : public juce::Component, public juce::Button::Listener {
public:
	AudioTrackComponent();

	void buttonClicked(juce::Button *button) override;
	void paint(juce::Graphics &g) override;
	void resized() override;

private:
	const int io_region_w;

	juce::ToggleButton solo_button;
	juce::ToggleButton mute_button;
	juce::ToggleButton wave_flip_button; // polarity flip toggle
	WaveformViewComponent waveform_view;
};
