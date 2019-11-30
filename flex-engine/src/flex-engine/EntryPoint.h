#pragma once

#ifdef FXE_PLATFORM_WINDOWS

extern Flex::Application* Flex::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Flex::CreateApplication();
	app->Run();
	delete app;
}


#endif