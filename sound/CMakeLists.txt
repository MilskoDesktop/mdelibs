include(MDEPkgConfig)

setup_lib(sound Sound)
target_link_libraries(
	MDESound
	PRIVATE
	MDECore Mw
)

pkg_config_add(MDESound vorbisfile)
