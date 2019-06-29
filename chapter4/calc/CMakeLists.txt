cmake_minimum_required (VERSION 2.6)
project (calc C)
# The version number
set (calc_VERSION_MAJOR 0)
set (calc_VERSION_MINOR 4.3)

configure_file (
	"${PROJECT_SOURCE_DIR}/calc.h.in"
	"${PROJECT_BINARY_DIR}/calc.h"
)

include_directories ("${PROJECT_BINARY_DIR}")

file (GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.c)")


# This is for practice
# Should we include the header? (of course...)
option (USE_HEADER
		"Should we include calc.h?" ON)

# Are we including headers? (yes...)
#
if (USE_HEADER)
	include_directories ("${PROJECT_SOURCE_DIR}/include")
	add_subdirectory (include)
	set (EXTRA_LIBS ${EXTRA_LIBS} include)
endif (USE_HEADER)


add_executable (calc "${SOURCES}")
target_link_libraries (calc CalcLibrary)

#add the install targets
install (TARGETS calc DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
		DESTINATION include)

