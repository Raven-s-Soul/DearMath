# ! Executable
add_executable(${PROJECT_NAME}
    project.cpp
    project.h
)

# ! Platform-specific configuration
if(UNIX AND NOT APPLE)
    message("Linux")
    find_package(PkgConfig REQUIRED)

    # pkg_check_modules(GLFW REQUIRED glfw3)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE app_external_deps
        OpenGL::GL
        PRIVATE ${LINUX_GL_LIBS}
        ${GLFW_STATIC_LIBRARIES})

    target_compile_options(${PROJECT_NAME} PRIVATE ${GLFW_CFLAGS})
endif()

if(APPLE)
    message("Mac OS X")

    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    find_library(COREVIDEO_LIBRARY CoreVideo)

    target_link_libraries(${PROJECT_NAME}
        glfw
        app_external_deps
        OpenGL::GL
        ${COCOA_LIBRARY}
        ${IOKIT_LIBRARY}
        ${COREVIDEO_LIBRARY})
    target_include_directories(${PROJECT_NAME}
        PRIVATE /usr/local/include
        /opt/local/include
        /opt/homebrew/include
    )
    link_directories(
        /usr/local/lib
        /opt/local/lib
        /opt/homebrew/lib
    )
endif()

if(WIN32)
    # ! target_link
    target_link_libraries(${PROJECT_NAME}
        OpenGL::GL
        app_external_deps
        glfw
    )
endif()
