#include <flex-engine.h>
#include <flex-math.h>

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
	FE::Matf m = FE::Matf();
	//m.log();
	

	return new Sandbox();
}