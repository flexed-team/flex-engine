
workspace "flex-engine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

-- example : "Debug-windows-x86_64"
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"	



-------------------------- PROJECTS -----------------------------


-- Flex Engine ------------------------------- 
project "flex-engine"
	location "flex-engine"
	kind "SharedLib"

	language "C++"
	
	-- example : "bin/Debug-windows-x86_64/flex-engine"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/flex-math/src",
		"%{prj.name}/vendor/flex-render/src",
		"%{prj.name}/vendor/glm/glm",
		"%{prj.name}/vendor/spdlog/include"
	}

	-- Windows options
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"FE_PLATFORM_WINDOWS",
			"FE_BUILD_DLL"
		}

		postbuildcommands
		{	-- will copy dll from engine build dir into sandbox build dir
			("{COPY} %{cfg.buildtarget.relpath} %{wks.location}/bin/" .. outputdir .. "/Sandbox/*")
		}


	-- General build modes options for platforms
	filter "configurations:Debug"
		defines "FE_DEBUG"
		symbols "On" -- acts like -g gcc flag

	filter "configurations:Release"
		defines "FE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FE_DIST"
		optimize "On"









-- Flex Math ------------------------------- 
project "flex-math"
	location "flex-engine/vendor/flex-math"
	kind "StaticLib"

	language "C++"

	files
	{
		"%{prj.location}/src/**.h",
	}

	-- Windows options
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"







-- Sandox ------------------------------- 
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"flex-engine/src",
		"flex-engine/vendor/flex-math/src",
		"flex-engine/vendor/flex-render/src",
		"flex-engine/vendor/glm/glm",
		"flex-engine/vendor/spdlog/include",
	}

	links
	{
      "flex-engine"
	}

	-- Windows options
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
         "FE_PLATFORM_WINDOWS"
		}

	-- General build modes options for platforms
	filter "configurations:Debug"
		defines "FE_DEBUG"
		symbols "On" -- acts like -g gcc flag

		
	filter "configurations:Release"
		defines "FE_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "FE_DIST"
      optimize "On"
      