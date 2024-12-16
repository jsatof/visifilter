#pragma once

//#ifndef JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED
//#define JUCE_GLOBAL_MODULE_SETTINGS_INCLUDED
//#endif

#include <juce_gui_basics/juce_gui_basics.h>

#include <components/editor_component.h>

class MainComponent final : public juce::Component {
public:
    MainComponent();

    void paint(juce::Graphics&) override;
    void resized() override;

private:
	EditorComponent editor_component;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
