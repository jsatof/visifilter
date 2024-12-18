cmake_minimum_required(VERSION 3.22)
project(visifilterSource VERSION 0.0.1)

juce_add_gui_app(visifilter
    # VERSION ...                               # Set this if the plugin version is different to the project version
    # ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
    # ICON_SMALL ...
    COMPANY_NAME "JamesFerrarelli"
    COMPANY_WEBSITE "https://github.com/jsatof"
    PRODUCT_NAME "visifilter")

juce_generate_juce_header(visifilter)

target_sources(visifilter
    PRIVATE
    	main.cpp
    	components/audio_component.cpp
        components/audio_track_component.cpp
    	components/editor_component.cpp
    	components/main_component.cpp
    	components/waveform_view_component.cpp
)

target_include_directories(visifilter
    PRIVATE
    	${JUCE_SOURCE_DIR}/modules
        .
)

target_compile_definitions(visifilter
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:visifilter,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:visifilter,JUCE_VERSION>")

target_link_libraries(visifilter
    PRIVATE
    	juce::juce_audio_utils
        fmt::fmt
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

install(TARGETS visifilter DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
