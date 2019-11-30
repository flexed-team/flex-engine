#include <flex-engine.h>

class Sandbox : public Flex::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

Flex::Application* Flex::CreateApplication()
{
	return new Sandbox();
}