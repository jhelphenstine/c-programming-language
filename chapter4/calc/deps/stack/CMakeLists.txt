cmake_minimum_required(VERSION 3.0)
project(DoubleStack VERSION 0.1.0 LANGUAGES "C")

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    option(STACK_WERROR "Build stack with -Werror (Defaults on for all except release" OFF)
else()
    option(STACK_WERROR "Build stack with -Werror (Defaults on for all except release" OFF)
endif()


set(stack_SRCS src/stack.c)


# For now you probably always want to build statically
add_library(stack_static STATIC ${stack_SRCS})
add_library(stack ALIAS stack_static)
# Is equivelent to 
#target_include_directories(stack_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(stack_static PUBLIC include)
target_compile_options(stack_static PRIVATE "-Wall" "-Wextra")
if(STACK_WERROR)
    target_compile_options(stack_static PRIVATE "-Werror")
endif()