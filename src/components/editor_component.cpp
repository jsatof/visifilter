#include <components/editor_component.h>

EditorComponent::EditorComponent() {
    addAndMakeVisible(audio_track);
}

void EditorComponent::resized() {
    audio_track.setBounds(audio_track.getLocalBounds());
}

void EditorComponent::paint(juce::Graphics &g) {
    g.setColour(juce::Colours::seagreen);
}



