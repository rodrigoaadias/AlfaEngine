#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Alfa
{
    std::shared_ptr<spdlog::logger> Log::sCoreLogger;
    std::shared_ptr<spdlog::logger> Log::sClientLogger;

    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        sCoreLogger = spdlog::stdout_color_mt("ALFA_ENGINE");
        sCoreLogger->set_level(spdlog::level::trace);
        
        sClientLogger = spdlog::stdout_color_mt("GAME_APP");
        sClientLogger->set_level(spdlog::level::trace);
    }
}
