cmake_minimum_required(VERSION 3.16)
project(loggy)

set(CMAKE_CXX_STANDARD 20)

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
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
    find_package(WindowsSDK REQUIRED)

    if (NOT WINDOWSSDK_FOUND)
        message(FATAL_ERROR "Windows SDK not found")
    endif()

    get_windowssdk_include_dirs(${WINDOWSSDK_DIRS} PLATFORM_INCLUDE_DIRECTORIES)
    get_windowssdk_library_dirs(${WINDOWSSDK_DIRS} PLATFORM_LINK_DIRECTORIES)

    set(PLATFORM_SOURCE_FILES src/windows.cpp)
endif()

if (UNIX AND NOT APPLE)
    set(PLATFORM_SOURCE_FILES src/linux.c)
endif (UNIX AND NOT APPLE)

add_executable(loggy main.cpp include/keylogger.h include/types.h include/json_writer.h ${PLATFORM_SOURCE_FILES} src/common/json_writer.cpp)
target_link_libraries(loggy ${PLATFORM_LINK_LIBRARIES})

if (PLATFORM_INCLUDE_DIRECTORIES)
    target_include_directories(loggy PRIVATE ${PLATFORM_INCLUDE_DIRECTORIES})
endif()

if(PLATFORM_LINK_DIRECTORIES)
    target_link_directories(loggy PRIVATE ${PLATFORM_LINK_DIRECTORIES})
endif()
