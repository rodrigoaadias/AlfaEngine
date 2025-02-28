#pragma once
#include "AlfaApplication.h"

int WindowsMain(IApplication* app)
{
    if(app == nullptr)
    {
        return  0;
    }

    AlfaApplication application;
    application.Run(app);
 
    return 1;
}

#define ALFA_APPLICATION(AppClass)                            \
int main(int argc, char** argv)                               \
{                                                             \
    IApplication* app = new AppClass();                       \
    return WindowsMain(app);                                  \
}                                                             