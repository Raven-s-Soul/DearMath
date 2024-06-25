#pragma once

#include "imgui.h"
#include "components.h"
#include "logger.h"
#include <string>

#define ANSWERS "-> "
#define TextSize 256

// static char logs[LOG_SIZE] = "";
static char text[TextSize] = "";

// static int TextEditCallbackStub(ImGuiInputTextCallbackData *data);

class Console
{
public:
    Console()
    {
        logger = Logger();
    }

    void draw(bool &isLoggerOn);

    Logger getLogger()
    {
        return logger;
    }

    int TextEditCallback(ImGuiInputTextCallbackData *data);

private:
    Logger logger;

    // ImVector<char *> History;
    // int HistoryPos = -1; // -1: new line, 0..History.Size-1 browsing history.

    void commandEnter();
};
