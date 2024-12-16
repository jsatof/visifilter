#include <components/editor_component.h>

static void toggleButtonState(juce::Button &button) {
	auto buttonDown = juce::Button::ButtonState::buttonDown;
	auto buttonUp = juce::Button::ButtonState::buttonNormal;
	const juce::Button::ButtonState new_state = (button.getState() == buttonUp) ? buttonDown : buttonUp;
	button.setState(new_state);
}

EditorComponent::EditorComponent()
	: solo_button("S")
    , mute_button("M")
    , wave_flip_button("F")
{
	solo_button.addListener(this);
	addAndMakeVisible(solo_button);

	mute_button.addListener(this);
	addAndMakeVisible(mute_button);

	wave_flip_button.addListener(this);
	addAndMakeVisible(wave_flip_button);

	addAndMakeVisible(waveform_view_component);
}

void EditorComponent::resized() {
	int margin = 50;
	int padding = 5;
	auto region = getLocalBounds();

	auto wave_view_bounds = region.removeFromBottom(region.getHeight() - margin);
	waveform_view_component.setBounds(wave_view_bounds);

	solo_button.setBounds(region.removeFromLeft(margin).reduced(padding));
	mute_button.setBounds(region.removeFromLeft(margin).reduced(padding));
	wave_flip_button.setBounds(region.removeFromLeft(margin).reduced(padding));
}

void EditorComponent::paint(juce::Graphics &g) {
	g.setColour(juce::Colours::seagreen);
	g.fillRect(waveform_view_component.getBounds());
}

void EditorComponent::buttonClicked(juce::Button *button) {
	if (button == &solo_button) {
		toggleButtonState(solo_button);
	}
	if (button == &mute_button) {
		toggleButtonState(mute_button);
	}
	if (button == &wave_flip_button) {
		toggleButtonState(wave_flip_button);
	}
}


