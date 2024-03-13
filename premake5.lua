outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

workspace "BitGameEngine"
    configurations { 
        "Debug", 
        "Release", 
        "Shipping"
    }

    startproject "Sandbox"

    include "BitCore/vendor/GLFW/premake5"

project "BitCore"
    location "BitCore"
    kind "StaticLib"
    language "C++"
    architecture "x64"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "%{prj.name}/Core/**.h", 
        "%{prj.name}/Core/**.cpp"
    }

    includedirs
    {
        '%{prj.name}/Include'
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
        "%{prj.name}/Include"
    }

    links
    {
        "BitCore"
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