# ! imgui_glfw
add_library(imgui_glfw STATIC
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
    imgui/misc/cpp/imgui_stdlib.cpp
)

# target_compile_definitions(imgui_glfw
# PRIVATE IMGUI_IMPL_OPENGL_LOADER_GLAD=1
# )
target_link_libraries(imgui_glfw PUBLIC glfw)

target_include_directories(imgui_glfw PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/imgui
    ${CMAKE_CURRENT_LIST_DIR}/imgui/backends
)

# ! app_external_deps
add_library(app_external_deps INTERFACE)
target_link_libraries(app_external_deps INTERFACE
    imgui_glfw

    # pthreadVC3 # pthread-win32
)