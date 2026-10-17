#pragma once 

#include <memory>

#include <spdlog/spdlog.h>

namespace Wave
{

class Log
{
public: 
    static void Init(); 

    inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; };

private: 
    static std::shared_ptr<spdlog::logger> s_Logger;
};

}

// Conditional Logging Macros based on NDEBUG (Release vs Debug)
#ifdef NDEBUG
    // --- RELEASE MODE ---
    // TRACE and INFO are compiled away to nothing (zero overhead)
    #define TRACE(...) ((void)0)
    #define INFO(...)  ((void)0)

    // WARN and ERROR remain active so you can debug production issues
    #define WARN(...)  ::Wave::Log::GetLogger()->warn(__VA_ARGS__)
    #define ERROR(...) ::Wave::Log::GetLogger()->error(__VA_ARGS__)
#else
    // --- DEBUG MODE ---
    // All logs are fully active
    #define TRACE(...) ::Wave::Log::GetLogger()->trace(__VA_ARGS__)
    #define INFO(...)  ::Wave::Log::GetLogger()->info(__VA_ARGS__)
    #define WARN(...)  ::Wave::Log::GetLogger()->warn(__VA_ARGS__)
    #define ERROR(...) ::Wave::Log::GetLogger()->error(__VA_ARGS__)
#endif