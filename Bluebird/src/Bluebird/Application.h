#pragma once

#include"core.h"

namespace Bluebird {
	class BLUEBIRD_API Application
	{
	public:
		virtual void run();
	};

	Application* createApplication();
}

