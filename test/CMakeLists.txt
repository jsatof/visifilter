cmake_minimum_required(VERSION 3.22)
project(visifilterTest)
enable_testing()

# source code static library
add_library(visifilterStatic
	STATIC
        ../src/audio_component.cpp
        ../src/editor_component.cpp
        ../src/main_component.cpp
        ../src/waveform_view_component.cpp
)

target_include_directories(visifilterStatic
    PRIVATE
        ../src
        .
)

target_compile_definitions(visifilterStatic
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(visifilterStatic
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

# test runner
add_executable(visifilterTest
    src/audio_processor_test.cpp
)

target_include_directories(visifilterTest
    PRIVATE
        ${GTEST_SOURCE_DIR}/googletest/include
        ${PROJECT_SOURCE_DIR}/../plugin/include
        ${JUCE_SOURCE_DIR}/modules)

target_link_libraries(visifilterTest
    PRIVATE
   		visifilterStatic
        GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(visifilterTest)
