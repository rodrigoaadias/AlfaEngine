#pragma once
#include "IApplication.h"

int WindowsMain(IApplication* app)
{
    if(app == nullptr)
    {
        return  0;
    }
    app->Init();
    app->Load();

    while (!app->WantsToQuit())
    {
        app->Update(0.16f);
    }

    app->Unload();
    app->Exit();    
    return 1;
}

#define BIT_APPLICATION(AppClass)                             \
int main(int argc, char** argv)                               \
{                                                             \
    IApplication* app = new AppClass();                       \
    return WindowsMain(app);                                  \
}                                                             