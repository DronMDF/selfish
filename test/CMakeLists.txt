cmake_minimum_required(VERSION 3.5)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# @todo #14 Find more usable way for share sources beetwen app and test
add_executable(
	selfish_test
	main.cpp
	../BlockNull.cpp
	BlockNullTest.cpp
)

set_target_properties(
	selfish_test
	PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
)

target_link_libraries(
	selfish_test
	${CONAN_LIBS}
)

add_test(
	NAME selfish_test
	COMMAND selfish_test
)
