#include "logger.h"

void Logger::draw(bool *p_open)
{
    ImGui::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
    if (!ImGui::Begin("Logs", p_open, ImGuiWindowFlags_MenuBar))
    {
        ImGui::End();
        return;
    }
    MenuLogger();
    ImGui::Text("System: ");

    // ImGui::Separator();

    ImGui::BeginChild("LogChild", ImVec2(0, 0), p_open, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_HorizontalScrollbar);

    for (const auto &log : logMessages)
    {
        ImGui::TextColored(log.color, log.message.c_str());
    }

    if (scrollToBottom)
    {
        ImGui::SetScrollHereY(1.0f);
        scrollToBottom = false;
    }
    ImGui::EndChild();

    ImGui::End();
}

void Logger::LogToFile()
{
    std::string str;
    for (LogMessage i : logMessages)
        str += i.message;
    ImGui::LogToFile(-1, LogFileName);
    ImGui::LogText(str.c_str());
    ImGui::LogFinish();
}

void Logger::Copy_to_clipboard()
{
    std::string str;
    for (LogMessage i : logMessages)
        str += i.message + " \n";
    ImGui::LogToClipboard();
    ImGui::LogText(str.c_str());
    ImGui::LogFinish();
}

void Logger::MenuLogger()
{
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Logger Options"))
        {
            if (ImGui::MenuItem("Copy to clipboard", NULL))
            {
                Copy_to_clipboard();
            }
            if (ImGui::MenuItem("Log to file", NULL))
            {
                LogToFile();
            }
            if (ImGui::MenuItem("Clear file logs", NULL))
            {
                delete_file(LogFileName);
            }
            if (ImGui::MenuItem("Clear logs", NULL))
            {
                clearLogs();
            }

            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }
}
