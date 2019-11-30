#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace FE {

	/** A class abstraction over spdlog library 
	to create and manage logging
	*/
	class FE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_CoreLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// __VA_ARGS__ represents ... macro pack arguments

// Core log macros
#define FE_CORE_ERROR(...)       ::FE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FE_CORE_WARN(...)        ::FE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FE_CORE_INFO(...)        ::FE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FE_CORE_TRACE(...)       ::FE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FE_CORE_FATAL(...)       ::FE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define FE_ERROR(...)            ::FE::Log::GetClientLogger()->error(__VA_ARGS__)
#define FE_WARN(...)             ::FE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FE_INFO(...)             ::FE::Log::GetClientLogger()->info(__VA_ARGS__)
#define FE_TRACE(...)            ::FE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FE_FATAL(...)            ::FE::Log::GetClientLogger()->fatal(__VA_ARGS__)

