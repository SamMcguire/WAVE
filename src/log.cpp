#include "pch.h"
#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Wave
{

    std::shared_ptr<spdlog::logger> Log::s_Logger;

    void Log::Init()
    {
        //%^ starts color range. [%T] is timestamp. %v is the message. %$ ends color range. 
        spdlog::set_pattern("%^[%T]: %v%$");
        s_Logger = spdlog::stdout_color_mt("Wave");
        s_Logger->set_level(spdlog::level::trace);
    }

}