cmake_minimum_required(VERSION 3.25)
project(
	mdelibs
)

file(
	GLOB
	MDELib_SRC
	src/*.c
)

add_library(
	MDELib
	SHARED
	${MDELib_SRC}
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
	DIRECTORY include/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
	FILES_MATCHING PATTERN "*.h"
)
