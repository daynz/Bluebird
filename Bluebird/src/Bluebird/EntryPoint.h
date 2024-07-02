#pragma once
#ifdef BB_PLATFORM_WINDOWS

extern Bluebird::Application* Bluebird::createApplication();

int main()
{
	auto app = Bluebird::createApplication();
	app->run();
	delete app;
}
#endif