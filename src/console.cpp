#include "console.h"

//
//* Logger
//

void logger()
{
    // static ImGuiInputTextFlags logflags = ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_AllowTabInput;
    // ImGui::InputTextMultiline("Logger", Console::logs, IM_ARRAYSIZE(Console::logs), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), logflags);
}

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
    // logger();
    if (log && isLoggerOn)
    {
        logger.draw(&log);
    }

    //*
    //* Buttons
    //*

    if (ImGui::Button("Copy to clipboard"))
    {
        logger.Copy_to_clipboard();
    }

    ImGui::SameLine();
    if (ImGui::Button("Log to file"))
    {
        logger.LogToFile();
    }

    ImGui::SameLine();
    if (ImGui::Button("Clear file logs"))
    {
        delete_file(LogFileName);
    }

    ImGui::SameLine();
    ImGui::Checkbox("Show Log", &log);

    //*
    //* Logic
    //*

    if (ImGui::IsWindowFocused() && ((ImGui::IsKeyReleased(ImGuiKey_Enter) || ImGui::IsKeyReleased(ImGuiKey_KeypadEnter))))
    {
        commandEnter();
    }

    //*
    //* Input
    //*

    ImGui::InputTextWithHint("Console", "...", text, IM_ARRAYSIZE(text));
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
