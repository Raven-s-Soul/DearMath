#pragma once
#include "imgui.h"
#include <cstdio>
#include <iostream>

// 	Debug Macro
//	1 - Active , 0 - Deactive
#define DEBUG_LOG 1

#if DEBUG_LOG
#define LOG(message) std::cout << message << std::endl;
#else
#define LOG(message)
#endif

static void HelpMarker(const char *desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::BeginItemTooltip())
    {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

void delete_file(const char *filename);