#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include <components/audio_track_component.h>

class EditorComponent : public juce::Component {
public:
    EditorComponent();

    void resized() override;
    void paint(juce::Graphics &g) override;

private:
    AudioTrackComponent audio_track;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditorComponent)
};
