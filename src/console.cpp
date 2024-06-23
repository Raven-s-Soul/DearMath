#include "console.h"

//
//* Logger
//

static ImGuiInputTextFlags logflags = ImGuiInputTextFlags_ReadOnly | ImGuiInputTextFlags_AllowTabInput;

void logger()
{
    ImGui::InputTextMultiline("Logger", Console::logs, IM_ARRAYSIZE(Console::logs), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), logflags);

    if (ImGui::Button("Copy to clipboard"))
    {
        ImGui::LogToClipboard();
        ImGui::LogText(Console::logs);
        ImGui::LogFinish();
    }

    ImGui::SameLine();
    if (ImGui::Button("Log to file"))
    {
        ImGui::LogToFile(-1, LogFileName);
        ImGui::LogText(Console::logs);
        ImGui::LogFinish();
    }

    ImGui::SameLine();
    if (ImGui::Button("Clear file logs"))
    {
        delete_file(LogFileName);
    }
}

void log_message(const char *message)
{
    std::string result(message);
    result += " \n";
    // Safely append the message to logs
    strncat(Console::logs, result.c_str(), LOG_SIZE - strlen(Console::logs) - 1);
}

//
//* Console
//

void commandEnter()
{
    //? Invio e finestra focussed

    //* Log to File
    {
        ImGui::LogToFile(-1, LogFileName);
        ImGui::LogText(Console::text);
        ImGui::LogFinish();
    }
    log_message(Console::text);

    //! Analisi
    /*
    std::string result(ANSWERS);
    result += "true";
    log_message(result.c_str());
    */

    //? Clear input after logging
    Console::text[0] = '\0';
    ImGui::SetKeyboardFocusHere();
}

void Console::console()
{
    ImGui::Begin("Console");

    logger();

    if (ImGui::IsWindowFocused() && ((ImGui::IsKeyReleased(ImGuiKey_Enter) || ImGui::IsKeyReleased(ImGuiKey_KeypadEnter))))
    {
        commandEnter();
    }

    ImGui::InputTextWithHint("Console", "...", Console::text, IM_ARRAYSIZE(Console::text));
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
