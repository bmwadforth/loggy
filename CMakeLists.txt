cmake_minimum_required(VERSION 3.16)
project(loggy C)

set(CMAKE_C_STANDARD 11)
add_executable(loggy main.c include/keystroke/keylogger.h src/keystroke/keylogger.c include/types.h)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

if (MACOSX)
    find_library(CARBON Carbon)
    if (NOT CARBON)
        message(FATAL_ERROR "Carbon not found")
    endif()

    find_library(APPLICATION_SERVICES ApplicationServices)
    if (NOT APPLICATION_SERVICES)
        message(FATAL_ERROR "ApplicationServices not found")
    endif()

    target_link_libraries(loggy ${CARBON} ${APPLICATION_SERVICES})
endif()