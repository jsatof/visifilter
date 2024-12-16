#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include <components/waveform_view_component.h>

class EditorComponent : public juce::Component, public juce::Button::Listener {
public:
	EditorComponent();

	void resized() override;
	void paint(juce::Graphics &g) override;
	void buttonClicked(juce::Button *button) override;

private:
	juce::ToggleButton solo_button;
	juce::ToggleButton mute_button;
	juce::ToggleButton wave_flip_button; // polarity flip toggle
	WaveformViewComponent waveform_view_component;
	//juce::Component playhead;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditorComponent)
};
