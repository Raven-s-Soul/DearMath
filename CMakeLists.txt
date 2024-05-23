cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_BUILD_TYPE "RelWithDebInfo")

# Needed for tests
set(CMAKE_CXX_COMPILER g++)

# set(CMAKE_CXX_COMPILER cl) # Using Visual Studio

# !Project
project(project)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

set(CMAKE_HAVE_LIBC_PTHREAD 1)

# !Auto Download from git all the submodules
find_package(Git QUIET)

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)

    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT)

        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# !Dependencies
# * https://www.glfw.org/docs/3.3/build_guide.html
add_subdirectory(external/glfw)

# * Imgui
add_subdirectory(external)

# * OpenGL
find_package(OpenGL REQUIRED)

# pthread-win32 for pthread on windows
# if(WIN32)
# add_subdirectory(external/pthread-win32)
# include_directories(external/pthreads-w32)
# set(PTHREADS_W32_LIBRARY pthread-win32)
# else()
# find_package(Threads REQUIRED)
# endif()

# !Build
add_subdirectory(src)
