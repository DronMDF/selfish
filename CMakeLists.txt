cmake_minimum_required(VERSION 3.5)

project(imp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

find_package(Threads)
conan_basic_setup()

add_executable(
	selfish
	main.cpp
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
	${CMAKE_THREAD_LIBS_INIT}
	${CONAN_LIBS}
)

enable_testing()
# @todo #1 Add unittest runner
#add_subdirectory(test)

# @todo #1 Add style check
#add_custom_target(
#	style
#	COMMAND ${CMAKE_SOURCE_DIR}/style.sh
#	WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
#)
