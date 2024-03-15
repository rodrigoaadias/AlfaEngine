#pragma once
#include "spdlog/spdlog.h"

namespace Alfa
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return sCoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return sClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> sCoreLogger;
        static std::shared_ptr<spdlog::logger> sClientLogger;
    };
}

// Core logs
#define AF_CORE_LOG_ERROR(...)      ::Alfa::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AF_CORE_LOG_WARN(...)       ::Alfa::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AF_CORE_LOG_INFO(...)       ::Alfa::Log::GetCoreLogger()->info(__VA_ARGS__)

// Client logs
#define AF_LOG_ERROR(...)           ::Alfa::Log::GetClientLogger()->error(__VA_ARGS__)
#define AF_LOG_WARN(...)            ::Alfa::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AF_LOG_INFO(...)            ::Alfa::Log::GetClientLogger()->info(__VA_ARGS__)