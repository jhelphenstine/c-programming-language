# Try not to use anything lower than 3
# Absolutely don't use anything lower than 2.8.12, that is when cmake got useful
# realistically dont go lower than 3
cmake_minimum_required(VERSION 3.0)
project (calc VERSION 0.4.3 LANGUAGES "C")

add_subdirectory(deps/stack)


# Prefer CMAKE_CURRENT to PROJECT_ incase you are added as a subdirectory
configure_file (
	"${CMAKE_CURRENT_SOURCE_DIR}/config.h.in"
	"${CMAKE_CURRENT_BINARY_DIR}/include/calc/config.h"
)


# Don't use globs. If you add a new file cmake won't pick it 
# up unless you re-run cmake
#file (GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.c)")
set(calc_SRCS
	src/getch.c
	src/getop.c
	src/main.c
)


add_executable (calc ${calc_SRCS})
target_include_directories(calc PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/include)
target_link_libraries (calc stack m)

#add the install targets
install (TARGETS calc DESTINATION bin)
#install (FILES "${PROJECT_BINARY_DIR}/config.h"
#		DESTINATION include)

