option(BUILD_TESTS OFF)

if (MSVC)
	set(HOME_DIR $ENV{USERPROFILE})
else()
	set(HOME_DIR $ENV{HOME})
endif()
# reconfigure by passing -DLV2_INSTALL_PREFIX=<your custom path> to cmake
set(LV2_INSTALL_PREFIX "${HOME_DIR}/.lv2")
set(VST3_INSTALL_PREFIX "${HOME_DIR}/.vst3")
set(AU_INSTALL_PREFIX "${HOME_DIR}/.au")
