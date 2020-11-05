#include <flex-engine.hpp>
#include <fstream>

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

void test(std::ofstream &f, char delim, std::function<void(void)> callback)
{
	auto t1 = std::chrono::high_resolution_clock::now();
	callback();
	auto t2 = std::chrono::high_resolution_clock::now();
	f << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << delim;
	//std::cout << "test took " << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds\n";
}

FE::Application *FE::create_application()
{
	std::srand(NULL);

	//FE::Matrix3<int> m = FE::Matrix3<int>(arr);
	//glm::mat3(0, 0, 0, 0, 0, 0, 0, 0, 0);

	std::ofstream f("test.csv");
	f << "FE::Matrix3\t"
	  << "glm::mat3\t";

	for (int k = 0; k < 100; k++)
	{

		test(f, '\t', []() {
			glm::mat4 *a = new glm::mat4[500];
			for (int i = 0; i < 500; i++)
				a[i] = glm::mat4(
					std::rand(), std::rand(), std::rand(), std::rand(),
					std::rand(), std::rand(), std::rand(), std::rand(),
					std::rand(), std::rand(), std::rand(), std::rand(),
					std::rand(), std::rand(), std::rand(), std::rand());
		});
		test(f, '\n', []() {
			FE::Matrix4<int> *a = new FE::Matrix4<int>[500];
			for (int i = 0; i < 500; i++)
				a[i] = FE::Matrix4<int>(
					std::rand(), std::rand(), std::rand(), std::rand(),
					std::rand(), std::rand(), std::rand(), std::rand(),
					std::rand(), std::rand(), std::rand(), std::rand(),
					std::rand(), std::rand(), std::rand(), std::rand());
		});
	}

	f.close();
	std::cout << "done!";

	return new Sandbox();
}