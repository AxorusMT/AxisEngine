workspace "AxisEngine"
    configurations {"Release", "Debug"}

project "AxisEngine"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    
    files {"src/**.cpp", "src/**.c", "src/**.h", "include/**.h"}

    -- Linking
    links {"SDL2", "GL", "dl", "pthread", "X11"}
    libdirs {"lib"}
    
    includedirs {"include"}

    buildoptions {"-Wl", "--no-as-needed"}
    
    filter "configurations:Debug"
        defines {"AXIS_DEBUG"}
        links {"bxDebug", "bgfxDebug", "bimgDebug"}
        symbols "On"
        
    filter "configurations:Release"
        defines {"AXIS_RELEASE"}
        links {"bxRelease", "bgfxRelease", "bimgRelease"}
        optimize "On"
