#pragma once

#ifdef BB_PLATFORM_WINDOWS
	#ifdef BB_BUILD_DLL
		#define BLUEBIRD_API __declspec(dllexport)
	#else
		#define BLUEBIRD_API __declspec(dllimport)
	#endif // BB_BUILD_DLL

#else
#error Bluebird only support Windows!

#endif // BB_PLATFORM_WINDOWS
