outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "AlfaEngine"
    configurations { 
        "Debug", 
        "Release", 
        "Shipping"
    }

    startproject "Sandbox"

include "vendor/GLFW/premake5"

project "Alfa"
    location "Engine"
    kind "StaticLib"
    language "C++"
    architecture "x64"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.location}/**.h", 
        "%{prj.location}/**.cpp"
    }

    includedirs
    {
        '%{prj.location}/*/Include',
        'vendor/spdlog/include'
    }

    filter "system:windows"
		systemversion "latest"
		toolset "v143"

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
        "Engine/*/Include",
        'vendor/spdlog/include'
    }

    links
    {
        "Alfa"
    }

    filter "system:windows"
        --systemversion "10.0.17763.0" -- General -> Windows SDK Version
		--toolset "v141" -- General -> Platform Toolset

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