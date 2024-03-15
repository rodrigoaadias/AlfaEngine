#include "Startup.h"

#include "Log.h"

void InitModules()
{
    Alfa::Log::Init();
    AF_CORE_LOG_INFO("Logging module started");
}
