#include "log.hpp"

namespace FE
{

	std::shared_ptr<spdlog::logger> Log::s_core_logger;
	std::shared_ptr<spdlog::logger> Log::s_client_logger;

	void Log::init()
	{
		// See spdlog [wiki](https://github.com/gabime/spdlog/wiki) for more pattern settings
		// ^ - start color range
		// T - ISO 8601 time format
		// n - logger's name
		// v - actual text to log
		// $ - end color range
		spdlog::set_pattern("%^[%T] %n: %v%$");
		// Create color multi threaded logger
		s_core_logger = spdlog::stdout_color_mt("FE");
		s_core_logger->set_level(spdlog::level::trace);

		s_client_logger = spdlog::stdout_color_mt("APP");
		s_client_logger->set_level(spdlog::level::trace);
	}

} // namespace FE