cmake_minimum_required(VERSION 3.16)
project(loggy C)

set(CMAKE_C_STANDARD 11)

if (APPLE)
    find_library(CARBON Carbon)
    if (NOT CARBON)
        message(FATAL_ERROR "Carbon not found")
    endif()

    find_library(APPLICATION_SERVICES ApplicationServices)
    if (NOT APPLICATION_SERVICES)
        message(FATAL_ERROR "ApplicationServices not found")
    endif()

    set(PLATFORM_SOURCE_FILES src/mac.c)
    set(PLATFORM_LINK_LIBRARIES ${CARBON} ${APPLICATION_SERVICES})
endif()

if (WIN32)
    set(PLATFORM_SOURCE_FILES src/windows.c)
endif()

if (UNIX AND NOT APPLE)
    set(PLATFORM_SOURCE_FILES src/linux.c)
endif (UNIX AND NOT APPLE)


add_executable(loggy main.c include/keylogger.h include/types.h ${PLATFORM_SOURCE_FILES})
target_link_libraries(loggy ${PLATFORM_LINK_LIBRARIES})
