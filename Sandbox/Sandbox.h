#pragma once
#include "Core/EntryPoint.h"
#include "Core/IApplication.h"

class Sandbox : public IApplication
{
public:
    void Init() override;
    void Load() override;
    void Update(float DeltaTime) override;
    void Unload() override;
    void Exit() override;
    const char* GetAppName() override;
    bool WantsToQuit() override;
};

ALFA_APPLICATION(Sandbox)