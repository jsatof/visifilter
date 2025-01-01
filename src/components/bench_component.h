#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

class BenchComponent : public juce::Component {
public:
    BenchComponent();

private:
    void perform_sine_sweep();
    void generate_gnuplot();

    std::vector<float> test_input;
};
