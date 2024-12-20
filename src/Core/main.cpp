#include "Application.h"
#include "../vendor/stb_image.h"

int main()
{
	Application* app = new Application();
	app->Run();
	delete app;
}