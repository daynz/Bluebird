#pragma once

#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"
namespace Bluebird {
	class BLUEBIRD_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

//Core log macros
#define BB_CORE_FATAL(...) ::Bluebird::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define BB_CORE_ERROR(...) ::Bluebird::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BB_CORE_WARN(...) ::Bluebird::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BB_CORE_INFO(...) ::Bluebird::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BB_CORE_TRACE(...) ::Bluebird::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client log macros
#define BB_FATAL(...) ::Bluebird::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define BB_ERROR(...) ::Bluebird::Log::GetClientLogger()->error(__VA_ARGS__)
#define BB_WARN(...) ::Bluebird::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BB_INFO(...) ::Bluebird::Log::GetClientLogger()->info(__VA_ARGS__)
#define BB_TRACE(...) ::Bluebird::Log::GetClientLogger()->trace(__VA_ARGS__)