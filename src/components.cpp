#include "components.h"

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