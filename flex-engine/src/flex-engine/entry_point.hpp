#pragma once

#ifdef FE_PLATFORM_WINDOWS

extern FE::Application *FE::create_application();

int main(int argc, char **argv)
{
	//FE::Matrix4 test = FE::Matrix4<double>(3, 3, 3, 4, 5, 6, 71562, 12134, 12,1,1,1,1,1,1,1);
	//test.log();

	FE::Log::init();
	//FE_CORE_WARN("Core logger initialized!");
	//int a = 5;
	//FE_INFO("a equals {0}", a);

	auto app = FE::create_application();
	app->run();
	delete app;
}

#endif