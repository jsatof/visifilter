#include <fmt/core.h>

#include <components/main_component.h>

static int main_width = 1000;
static int main_height = 750;

MainComponent::MainComponent() {
    setSize(main_width, main_height);
    addAndMakeVisible(editor_component);
    setVisible(false);
}

void MainComponent::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::cornflowerblue);
    g.setColour(juce::Colours::beige);
    g.setFont(16.f);
}

void MainComponent::resized() {
    editor_component.setBounds(getLocalBounds());
}
