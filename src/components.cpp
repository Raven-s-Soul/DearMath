#include "components.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

void OpenURL(const char *url)
{
#ifdef _WIN32
    ShellExecuteA(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
#else
    std::string command = "xdg-open ";
    command += url;
    std::system(command.c_str());
#endif
}

void delete_file(const char *filename)
{
    if (std::remove(filename) == 0)
    {
        LOG("File deletion successfully")
    }
    else
    {
        LOG("File deletion failed")
    }
}

std::string getCurrentDateTime()
{
    // Get the current time
    auto now = std::chrono::system_clock::now();
    // Convert it to time_t, which is a type suitable for representing calendar time
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Create a tm struct for local time
    std::tm local_tm;
#if defined(_MSC_VER) || defined(__MINGW32__)
    localtime_s(&local_tm, &now_time_t);
#else
    localtime_r(&now_time_t, &local_tm);
#endif

    // Format the time into a string
    std::ostringstream oss;
    oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void MenuBar(bool &showConsole, bool &isLoggerOn, bool &isAboutOn)
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Options"))
        {

            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Windows"))
        {
            ImGui::MenuItem("Console", NULL, &showConsole);
            ImGui::MenuItem("Logger", NULL, &isLoggerOn);
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("About"))
        {
            ImGui::MenuItem("This Project", NULL, &isAboutOn);
            ImGui::EndMenu();
        }
        /*
        if (ImGui::BeginMenu("File"))
        {
            // ShowExampleMenuFile();
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "CTRL+Z"))
            {
            }
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false))
            {
            } // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X"))
            {
            }
            if (ImGui::MenuItem("Copy", "CTRL+C"))
            {
            }
            if (ImGui::MenuItem("Paste", "CTRL+V"))
            {
            }
            ImGui::EndMenu();
        }
        */
        ImGui::EndMainMenuBar();
    }
}

void About(bool &isAboutOn)
{
    ImGui::Begin("About", &isAboutOn, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoResize);
    ImGui::Text("For more information, visit: ");
    ImGui::SameLine();
    if (ImGui::Button("GitHub"))
    {
        OpenURL("https://github.com/Raven-s-Soul/DearMath");
    }
    ImGui::End();
}

//* InputText

/*
    // To wire InputText() with std::string or any other custom string type,
    // see the "Text Input > Resize Callback" section of this demo, and the misc/cpp/imgui_stdlib.h file.
    // IMGUI_DEMO_MARKER("Widgets/Basic/InputText");
    static char str0[128] = "Hello, world!";
    ImGui::InputText("input text", str0, IM_ARRAYSIZE(str0));
    ImGui::SameLine();
    HelpMarker(
        "USER:\n"
        "Hold SHIFT or use mouse to select text.\n"
        "CTRL+Left/Right to word jump.\n"
        "CTRL+A or Double-Click to select all.\n"
        "CTRL+X,CTRL+C,CTRL+V clipboard.\n"
        "CTRL+Z,CTRL+Y undo/redo.\n"
        "ESCAPE to revert.\n\n"
        "PROGRAMMER:\n"
        "You can use the ImGuiInputTextFlags_CallbackResize facility if you need to wire InputText() "
        "to a dynamic string type. See misc/cpp/imgui_stdlib.h for an example (this is not demonstrated "
        "in imgui_demo.cpp).");

    static char str1[128] = "";
    ImGui::InputTextWithHint("input text (w/ hint)", "enter text here", str1, IM_ARRAYSIZE(str1));

    // IMGUI_DEMO_MARKER("Widgets/Basic/InputInt, InputFloat");
    static int i0 = 123;
    ImGui::InputInt("input int", &i0);

    static float f0 = 0.001f;
    ImGui::InputFloat("input float", &f0, 0.01f, 1.0f, "%.3f");

    static double d0 = 999999.00000001;
    ImGui::InputDouble("input double", &d0, 0.01f, 1.0f, "%.8f");

    static float f1 = 1.e10f;
    ImGui::InputFloat("input scientific", &f1, 0.0f, 0.0f, "%e");
    ImGui::SameLine();
    HelpMarker(
        "You can input value using the scientific notation,\n"
        "  e.g. \"1e+8\" becomes \"100000000\".");

    static float vec4a[4] = {0.10f, 0.20f, 0.30f, 0.44f};
    ImGui::InputFloat3("input float3", vec4a);

    // ImGui::Text("Hellooooo!");
    ImGui::End();

*/