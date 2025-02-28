#pragma once

class IApplication
{
public:
    
    virtual void Init() = 0;
    virtual void Load() = 0;
    virtual void Update(float DeltaTime) = 0;
    virtual void Unload() = 0;
    virtual void Exit() = 0;

    virtual const char* GetAppName() = 0;

    virtual bool WantsToQuit() = 0;
};
