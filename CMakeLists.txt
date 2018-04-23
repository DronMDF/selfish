cmake_minimum_required(VERSION 3.5)

project(selfish)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

add_executable(
	selfish
	main.cpp
	FairMiner.cpp
	MinedBlocks.cpp
)

set_target_properties(
	selfish
	PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)
target_link_libraries(
	selfish
	${CONAN_LIBS}
)

enable_testing()
add_subdirectory(test)

add_custom_target(
	style
	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
