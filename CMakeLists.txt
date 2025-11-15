cmake_minimum_required(VERSION 3.25)
project(
	mdelibs
	VERSION 0.0
	DESCRIPTION "MDE Libraries"
)

file(
	GLOB
	SOURCES
	src/*.c
)

add_library(
	MDELib
	SHARED
	${SOURCES}
)

target_include_directories(
	MDELib
	PUBLIC
	include
)

include(GNUInstallDirs)
install(
	TARGETS MDELib
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	FILES_MATCHING PATTERN "*.h"
)
