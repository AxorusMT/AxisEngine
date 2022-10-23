workspace "AxisEngine"
    configurations {"Release", "Debug"}

project "AxisEngine"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    
    files {"src/**.cpp", "src/**.c", "src/**.h", "include/**.h"}

    -- Linking to SDL2, opengl, and dl (idk if i need this)
    links {"SDL2", "GL", "dl"}
    includedirs {"include"}
    filter "configurations:Debug"
        defines {"AXIS_DEBUG"}
        symbols "On"
        
    filter "configurations:Release"
        defines {"AXIS_RELEASE"}
        optimize "On"
