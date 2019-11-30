#pragma once


#ifdef FXE_PLATFORM_WINDOWS
#	ifdef FXE_BUILD_DLL
#		define FLEX_API _declspec(dllexport)
#	else 
#		define FLEX_API _declspec(dllimport)
#	endif
#else 
#	error Flex engine supports only Widnows
#endif