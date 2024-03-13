#include "Sandbox.h"

#include <iostream>

#include "../BitCore/Core/Include/Core.h"

void Sandbox::Init()
{
    int x = 10;
    ASSERT(x == 10)  
}

void Sandbox::Load()
{
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

const std::string& Sandbox::GetAppName()
{
    return {"Sandbox"};
}

bool Sandbox::WantsToQuit()
{
    return false;
}
