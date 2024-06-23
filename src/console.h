#pragma once

#include "imgui.h"
#include "components.h"
#include "logger.h"
#include <string>

#define ANSWERS "-> "

// static char logs[LOG_SIZE] = "";
static char text[256] = "";

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

private:
    Logger logger;

    void commandEnter();
};
