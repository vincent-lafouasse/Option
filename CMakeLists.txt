cmake_minimum_required(VERSION 3.16)

project(PossOption
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -g3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-color=always")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(possOption INTERFACE)
target_sources(possOption INTERFACE
	./include/poss/Option.hpp
)
target_include_directories(possOption INTERFACE
	./include
)

add_executable(test)
target_sources(test PRIVATE
	test/main.cpp
)
target_link_libraries(test PUBLIC
	possOption
)
