#pragma once

#include "imgui.h"
#include "components.h"
#include <string>

#define LogFileName "ConsoleLog.txt"
#define LOG_SIZE 2048
#define ANSWERS "-> "

namespace Console
{
    static char logs[LOG_SIZE] = "";
    static char text[128] = "";

    void console();

}