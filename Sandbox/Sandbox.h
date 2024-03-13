#pragma once
#include "../BitCore/Core/Include/EntryPoint.h"
#include "../BitCore/Core/Include/IApplication.h"

class Sandbox : public IApplication
{
public:
    void Init() override;
    void Load() override;
    void Update(float DeltaTime) override;
    void Unload() override;
    void Exit() override;
    const std::string& GetAppName() override;
    bool WantsToQuit() override;
};

BIT_APPLICATION(Sandbox)