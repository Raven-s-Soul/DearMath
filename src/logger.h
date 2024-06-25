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

    ~Logger()
    {
        clearLogs();
        // Hystory.clear();
    }

    void log(std::string &message, const ImVec4 &color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f))
    {
        // Hystory.push_back(message);
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

    void clearLogs()
    {
        logMessages.clear();
    }

    void draw(bool *p_open);

    void LogToFile();

    void Copy_to_clipboard();

    bool scrollToBottom;

    // void HystoryClear()
    // {
    //     Hystory.clear();
    // }

    // const char *getHystory()
    // {
    //     if (HystoryScroll <= 0 || Hystory.empty() || Hystory.size() < HystoryScroll)
    //         return "";
    //     // LOG((Hystory.at(Hystory.size() - HystoryScroll) + "\0"))
    //     // return Hystory.at(Hystory.size() - HystoryScroll).c_str();
    //     return Hystory[Hystory.size() - HystoryScroll].c_str();
    // }

    // void incHystory()
    // {
    //     if (Hystory.size() > HystoryScroll)
    //         HystoryScroll++;
    //     // LOG(HystoryScroll)
    // }

    // void decHystory()
    // {
    //     if (HystoryScroll <= 0)
    //         return;
    //     HystoryScroll--;
    //     // LOG(HystoryScroll)
    // }

private:
    std::vector<LogMessage> logMessages;
    // std::vector<std::string> Hystory;
    // int HystoryScroll = 0;
    //  TODO ImVector<char *> Items;
    //  TODO ImVector<const char *> Commands;
    //  ImVector<std::string> Hystory;

    void MenuLogger();
};