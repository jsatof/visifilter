#include <format>
#include <random>
#include <print>

#include <components/bench_component.h>
#include <util/io.h>
#include <util/ring_buffer.h>

static inline std::vector<float> generateRandomInput();

BenchComponent::BenchComponent()
    : test_input(generateRandomInput())
{
    std::print("test_input: {}\n", test_input[3]);
    generate_gnuplot();
}

void BenchComponent::perform_sine_sweep() {
    RingBuffer<float> ring_buffer = {};
}

void BenchComponent::generate_gnuplot() {
    juce::File plot_file = util::createNewPlotFile();
    if (plot_file == juce::File{}) {
        std::print("skipping plot creation\n");
        return;
    }
    std::print("plot_file path: {}\n", plot_file.getFullPathName().toStdString());

    std::string title = "test data";

    plot_file.appendText(std::format("set title '{}'\n", title));
    plot_file.appendText("set terminal wxt size 1920,1080\n");
    plot_file.appendText("set xlabel 'time'\n");
    plot_file.appendText("set ylabel 'amplitude'\n");

    plot_file.appendText("plot '-' w lines lc rgb 'blue' title \"sampled data\", '-' w lines lc rgb 'red' title \"Filtered data\"\n");
    for (size_t i = 0; i < test_input.size(); ++i) {
        plot_file.appendText(std::format("{} {}\n", i, test_input.at(i)));
    }
}

std::vector<float> generateRandomInput() {
    std::vector<float> out;
    auto rng = std::uniform_real_distribution<float>{ -100.f, 100.f };
    auto rng_state = std::mt19937{ 1969 };
    const size_t size = 1024;
    float min_noise = 0.f;
    float max_noise = 0.3f;
    float freq = 3.54f;

    for (size_t i = 0; i < size; ++i) {
        out.push_back(rng(rng_state) * 100.f);
        float noise = min_noise + (float(rng(rng_state) / float(rng.max()))) * (max_noise - min_noise);
        out.push_back(std::sin(2.f * float(M_PI) * freq * (float(i) / float(size)) + noise));
    }
    return out;
}
