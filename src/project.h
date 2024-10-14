#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h> // Will drag system OpenGL headers
#include <chrono>
#include <thread>
#include "console.h"

// Global variable to track whether rendering should occur
#define FramesNext 10 // 1/6 s
int framesToRender = FramesNext;

// Key callback for GLFW
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

// Mouse callback for GLFW
void mouseCallback(GLFWwindow *window, double xpos, double ypos);

// Mouse button callback for GLFW
void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

class project
{
private:
    // Example of data used in the main loop
    ImVec4 clear_color;
    bool show_demo_window = true;
    bool show_another_window = false;
    Console console;

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
