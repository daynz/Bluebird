#include"Bluebird.h"

class Sandbox : public Bluebird::Application
{

};

Bluebird::Application* Bluebird::createApplication()
{
	return new Sandbox();
}