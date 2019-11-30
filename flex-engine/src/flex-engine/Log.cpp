#include "Log.h"

namespace FE {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		// See spdlog [wiki](https://github.com/gabime/spdlog/wiki) for more pattern settings 
		// ^ - start color range
		// T - ISO 8601 time format
		// n - logger's name
		// v - actual text to log
		// $ - end color range
		spdlog::set_pattern("%^[%T] %n: %v%$");
		// Create color multi threaded logger
		s_CoreLogger = spdlog::stdout_color_mt("FE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}