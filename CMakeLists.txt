cmake_minimum_required(VERSION 3.12)
project(CtfRelated)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE RELEASE)

add_executable(canary canary.c)
set_target_properties(canary PROPERTIES
        COMPILE_FLAGS "-fstack-protector")
set_property(TARGET canary APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie -z execstack")

add_executable(ret2text ret2text.c)
set_target_properties(ret2text PROPERTIES
        COMPILE_FLAGS " -fno-stack-protector -Wno-implicit-function-declaration")
set_property(TARGET ret2text APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie -z execstack")

add_executable(ret2text32 ret2text.c)
set_target_properties(ret2text32 PROPERTIES
        COMPILE_FLAGS " -fno-stack-protector -Wno-implicit-function-declaration -m32 ")
set_property(TARGET ret2text32 APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie -z execstack -m32 ")

add_executable(ret2shellcode ret2shellcode.c)
set_target_properties(ret2shellcode PROPERTIES
        COMPILE_FLAGS " -fno-stack-protector -Wno-implicit-function-declaration")
set_property(TARGET ret2shellcode APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie -z execstack")

add_executable(ret2shellcode32 ret2shellcode.c)
set_target_properties(ret2shellcode32 PROPERTIES
        COMPILE_FLAGS " -fno-stack-protector -Wno-implicit-function-declaration -m32 ")
set_property(TARGET ret2shellcode32 APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie -z execstack -m32 ")

add_executable(ret2syscall ret2syscall.c)
set_target_properties(ret2syscall PROPERTIES
        COMPILE_FLAGS " -fno-stack-protector -Wno-implicit-function-declaration")
set_property(TARGET ret2syscall APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie ")

add_executable(ret2syscall32 ret2syscall.c)
set_target_properties(ret2syscall32 PROPERTIES
        COMPILE_FLAGS " -fno-stack-protector -Wno-implicit-function-declaration -m32 ")
set_property(TARGET ret2syscall32 APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie -m32 ")

add_executable(ret2libc ret2libc.c)
set_target_properties(ret2libc PROPERTIES
        COMPILE_FLAGS " -fno-stack-protector -Wno-implicit-function-declaration")
set_property(TARGET ret2libc APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie ")

add_executable(ret2libc32 ret2libc.c)
set_target_properties(ret2libc32 PROPERTIES
        COMPILE_FLAGS " -fno-stack-protector -Wno-implicit-function-declaration -m32 ")
set_property(TARGET ret2libc32 APPEND_STRING
        PROPERTY LINK_FLAGS " -no-pie -m32 ")

