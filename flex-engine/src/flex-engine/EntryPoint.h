#pragma once

#ifdef FE_PLATFORM_WINDOWS

extern FE::Application* FE::CreateApplication();

int main(int argc, char** argv)
{
	FE::Log::Init(); 
	//FE_CORE_WARN("Core logger initialized!");
	//int a = 5;
	//FE_INFO("a equals {0}", a);

	auto app = FE::CreateApplication();
	app->Run();
	delete app;
}


#endif