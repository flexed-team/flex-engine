#pragma once
#include <flex-math.h>

#ifdef FE_PLATFORM_WINDOWS

extern FE::Application* FE::CreateApplication();

int main(int argc, char** argv)
{
	FE::Matrix4 test = FE::Matrix4<double>(3, 3, 3, 4, 5, 6, 71562, 12134, 12,1,1,1,1,1,1,1);
	test.log();

	FE::Log::Init();
	//FE_CORE_WARN("Core logger initialized!");
	//int a = 5;
	//FE_INFO("a equals {0}", a);

	auto app = FE::CreateApplication();
	app->Run();
	delete app;
}


#endif