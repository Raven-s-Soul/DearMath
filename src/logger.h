#pragma once

#include "imgui.h"
#include "components.h"
#include <vector>

#define LOG_SIZE 2048
#define LogFileName "ConsoleLog.txt"

struct LogMessage
{
    std::string message;
    ImVec4 color;

    LogMessage(const std::string &msg, const ImVec4 &col)
        : message(msg), color(col) {}
};

class Logger
{
public:
    Logger()
    {
        logMessages.push_back(LogMessage(getCurrentDateTime() + "\n", ImVec4(1.0f, 0.0f, 0.0f, 1.0f)));
    }

    void log(const std::string &message, const ImVec4 &color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f))
    {
        logMessages.push_back(LogMessage(message, color));
        scrollToBottom = true;
    }

    void log_message(const char *message)
    {
        std::string result(message);
        result += " \n";
        // Safely append the message to logs
        log(result, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
        // strncat(logs, result.c_str(), LOG_SIZE - strlen(logs) - 1);
    }

    // TODO to add
    void clearLogs()
    {
        logMessages.clear();
    }

    void draw(bool *p_open);

    void LogToFile();

    void Copy_to_clipboard();

    bool scrollToBottom;

private:
    std::vector<LogMessage> logMessages;
};