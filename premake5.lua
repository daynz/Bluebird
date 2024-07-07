workspace "Bluebird"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Bluebird/3rdParty/spdlog/include",
        "Bluebird/src"
    }

    links
    {
        "Bluebird"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22621.0"

        defines
        {
            "BB_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "BB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BB_DIST"
        symbols "On"


project "Bluebird"
    location "Bluebird"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/3rdParty/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22621.0"

        defines
        {
            "BB_PLATFORM_WINDOWS",
            "BB_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "BB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "BB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "BB_DIST"
        symbols "On"

