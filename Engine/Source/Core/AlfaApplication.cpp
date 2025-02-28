#include "afpch.h"
#include "Core/AlfaApplication.h"
#include "Core/IApplication.h"
#include "Core/Log.h"

void AlfaApplication::Run(IApplication* app)
{
    InitModules();

    app->Init();
    app->Load();

    while (!app->WantsToQuit())
    {
        app->Update(0.16f);
    }

    app->Unload();
    app->Exit();
}

void AlfaApplication::InitModules()
{
    Alfa::Log::Init();
    AF_CORE_LOG_INFO("Logging module started");
}
