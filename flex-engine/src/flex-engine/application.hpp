#pragma once

#include "core.hpp"

namespace FE
{

	class FE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	/** To be defined in client */
	Application *create_application();

} // namespace FE