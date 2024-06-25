#include "console.h"

//
//* Console
//

void Console::commandEnter()
{
    //? Invio e finestra focussed

    //* Log to File
    {
        ImGui::LogToFile(-1, LogFileName);
        ImGui::LogText(text);
        ImGui::LogFinish();
    }

    logger.log_message(text);
    // History.push_back(text);

    //! Analisi
    /*
    std::string result(ANSWERS);
    result += "true";
    log_message(result.c_str());
    */

    //? Clear input after logging
    text[0] = '\0';
    ImGui::SetKeyboardFocusHere();
}

void Console::draw(bool &isLoggerOn)
{
    static bool log = true;

    ImGui::Begin("Console");

    if (log && isLoggerOn)
    {
        logger.draw(&log);
    }

    // ImGui::SameLine();
    // ImGui::Checkbox("Show Log", &log);

    //*
    //* Logic
    //*

    if (ImGui::IsWindowFocused())
    {
        if ((ImGui::IsKeyReleased(ImGuiKey_Enter) || ImGui::IsKeyReleased(ImGuiKey_KeypadEnter)))
            commandEnter();
        /*
        if (ImGui::IsKeyReleased(ImGuiKey_UpArrow))
        {
        }

        if (ImGui::IsKeyReleased(ImGuiKey_DownArrow))
        {
        }
        */
    }

    //*
    //* Input
    //*

    ImGui::InputTextWithHint("Console", "...", text, IM_ARRAYSIZE(text)); // ImGuiInputTextFlags_CallbackHistory | ImGuiInputTextFlags_CallbackCompletion
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

    ImGui::End();
}