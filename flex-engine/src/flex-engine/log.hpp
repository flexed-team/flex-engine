#pragma once

#include <memory>

#include "core.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace FE {

	/** A class abstraction over spdlog library to create and manage logging */
	class FE_API Log
	{
	public:
		static void init();

		static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_core_logger; }
		static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_client_logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_core_logger;
		static std::shared_ptr<spdlog::logger> s_client_logger;
	};
	
}

// __VA_ARGS__ represents ... macro pack arguments

// Core log macros
#define FE_CORE_ERROR(...)       ::FE::Log::get_core_logger()->error(__VA_ARGS__)
#define FE_CORE_WARN(...)        ::FE::Log::get_core_logger()->warn(__VA_ARGS__)
#define FE_CORE_INFO(...)        ::FE::Log::get_core_logger()->info(__VA_ARGS__)
#define FE_CORE_TRACE(...)       ::FE::Log::get_core_logger()->trace(__VA_ARGS__)
#define FE_CORE_FATAL(...)       ::FE::Log::get_core_logger()->fatal(__VA_ARGS__)

// Client log macros
#define FE_ERROR(...)            ::FE::Log::get_client_logger()->error(__VA_ARGS__)
#define FE_WARN(...)             ::FE::Log::get_client_logger()->warn(__VA_ARGS__)
#define FE_INFO(...)             ::FE::Log::get_client_logger()->info(__VA_ARGS__)
#define FE_TRACE(...)            ::FE::Log::get_client_logger()->trace(__VA_ARGS__)
#define FE_FATAL(...)            ::FE::Log::get_client_logger()->fatal(__VA_ARGS__)

