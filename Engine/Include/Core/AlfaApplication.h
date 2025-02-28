#pragma once

class IApplication;

class AlfaApplication
{
public:
    void Run(IApplication* application);

private:
    void InitModules();
};