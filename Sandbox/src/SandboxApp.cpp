#include <flex-engine.h>

class Sandbox : public FE::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}
};

FE::Application* FE::CreateApplication()
{
	return new Sandbox();
}