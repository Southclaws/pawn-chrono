cmake_minimum_required(VERSION 3.0)

project(pawn-chrono)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib/cmake-modules")

if(UNIX)
	set(CMAKE_CXX_FLAGS "-m32 -fvisibility=hidden")
	set(CMAKE_C_FLAGS "-m32 -fvisibility=hidden")
	set_property(GLOBAL PROPERTY FIND_LIBRARY_USE_LIB64_PATHS OFF)
endif()

# removes the sprintf warnings from plugin-natives
add_definitions(
	-D_CRT_SECURE_NO_WARNINGS
	-D_SILENCE_CXX17_UNCAUGHT_EXCEPTION_DEPRECATION_WARNING
	-DUSE_SYSTEM_TZ_DB=ON
)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/test/plugins)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# no idea why this is necessary...
if(UNIX)
	set(ENABLE_DATE_TESTING OFF CACHE BOOL "Enable unit tests")
	set(USE_SYSTEM_TZ_DB ON CACHE BOOL "Use the operating system's timezone database")
elseif(WIN32)
	set(ENABLE_DATE_TESTING OFF)
	set(USE_SYSTEM_TZ_DB ON)
endif()

add_subdirectory(lib/date)
include_directories(lib/date/include)
add_subdirectory(src)
