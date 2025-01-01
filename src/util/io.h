#pragma once

#include <chrono>
#include <filesystem>

#include <juce_core/juce_core.h>

namespace fs = std::filesystem;

namespace util {

inline juce::File convertToJuceFile(const fs::path &p) {
    return { p.string() };
}

inline juce::File getProgramPath() {
    return juce::File::getSpecialLocation(juce::File::SpecialLocationType::currentExecutableFile);
}

// to be used as a filename prefix for gnuplots
inline std::string getDateTimePrefix() {
    const auto now = std::chrono::system_clock::now();
    const auto floored_days = std::chrono::floor<std::chrono::days>(now);
    const auto ymd = std::chrono::year_month_day{ floored_days };
    const auto hms = std::chrono::hh_mm_ss{ std::chrono::floor<std::chrono::seconds>(now - floored_days) };
    return std::format("{}_{}-{}-{}", ymd, hms.hours(), hms.minutes(), hms.seconds());
}

// path may change
inline juce::File createNewPlotFile() {
    juce::File base = getProgramPath();
    for (int i = 0; i < 5; ++i) {
        base = base.getParentDirectory();
    }
    base = base.getChildFile("plots");
    jassert(base.exists());
    if (base.getNumberOfChildFiles(juce::File::TypesOfFileToFind::findFiles) != 0) {
        return {};
    }
    return { base.getChildFile(getDateTimePrefix() + std::string{ ".gnuplot" }) };
}

}
