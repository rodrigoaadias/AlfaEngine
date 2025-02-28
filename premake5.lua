outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "AlfaEngine"
    configurations { 
        "Debug", 
        "Release", 
        "Shipping"
    }

    startproject "Sandbox"

IncludeDirs = {}
IncludeDirs["GLFW"] = "vendor/GLFW/include"

include "vendor/GLFW/premake5"

project "Alfa"
    location "Engine"
    kind "StaticLib"
    language "C++"
    architecture "x64"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "afpch.h"
    pchsource "Engine/Source/afpch.cpp"

    files 
    { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    includedirs
    {
        '%{prj.location}/Include',
        'vendor/spdlog/include',
        '%{IncludeDirs.GLFW}'
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
		systemversion "latest"
		toolset "v143"
        defines
        {
            "AF_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines 
        {
            "DEBUG" 
        }
        symbols "On"

    filter "configurations:Release"
        defines 
        { 
           "NDEBUG"
        }
        optimize "On"
    
    filter "configurations:Shipping"
        defines 
        { 
           "NDEBUG" 
        }
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    architecture "x64"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/**.h", 
        "%{prj.name}/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/Include",
        "Engine/Include",
        'vendor/spdlog/include'
    }

    links
    {
        "Alfa"
    }

    filter "system:windows"
        systemversion "latest" -- General -> Windows SDK Version
		toolset "v143" -- General -> Platform Toolset

        defines
        {
            "AF_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines 
        {
            "DEBUG"
        }
        symbols "On"

    filter "configurations:Release"
        defines 
        { 
           "NDEBUG"
        }
        optimize "On"
    
    filter "configurations:Shipping"
        defines 
        { 
           "NDEBUG" 
        }
        optimize "On"