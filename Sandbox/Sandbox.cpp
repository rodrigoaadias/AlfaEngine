#include "Sandbox.h"
#include "Core/Log.h"

void Sandbox::Init()
{
    AF_LOG_INFO("Starting game app: {}", GetAppName());
}

void Sandbox::Load()
{
    AF_LOG_WARN("Loading data");
    AF_LOG_ERROR("Loaded game {}", GetAppName()); 
}

void Sandbox::Update(float DeltaTime)
{
}

void Sandbox::Unload()
{
}

void Sandbox::Exit()
{
}

const char* Sandbox::GetAppName()
{
    return "Sandbox";
}

bool Sandbox::WantsToQuit()
{
    return false;
}
