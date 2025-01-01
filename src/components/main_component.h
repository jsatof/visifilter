#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include <components/bench_component.h>
#include <components/editor_component.h>

class MainComponent final : public juce::Component {
public:
    MainComponent();

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    EditorComponent editor_component;
    BenchComponent bench_component;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
