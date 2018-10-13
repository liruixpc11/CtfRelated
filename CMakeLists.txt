cmake_minimum_required(VERSION 3.12)
project(CtfRelated)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_executable(canary canary.c)
set_target_properties(canary PROPERTIES
        COMPILE_FLAGS "-fno-stack-protector")
set_property(TARGET canary APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie -z execstack")
