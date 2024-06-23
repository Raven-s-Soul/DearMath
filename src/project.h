#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include <chrono>
#include <thread>

class project
{
private:
    // Example of data used in the main loop
    ImVec4 clear_color;
    bool show_demo_window = true;
    bool show_another_window = false;

public:
    void Init(GLFWwindow *window, const char *glsl_version);
    virtual void Update();
    void Render(GLFWwindow *window);
    void Shoutdown(GLFWwindow *window);
    void newFrame();

public:
    project(ImVec4 vec)
    {
        this->clear_color = vec;
    }
};
