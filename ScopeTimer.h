#pragma once

#include <chrono>
#include <iostream>

class ScopeTimer
{
public:
	using Clock = std::chrono::steady_clock;

	ScopeTimer(const char* message) :
		message_(message),
		start_(Clock::now()) {}

	~ScopeTimer()
	{
		auto stop = Clock::now();
		auto duration = stop - start_;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds> (duration).count();
		std::cout << ms << "ms" << " : " << message_ << std::endl;
	}

private:
	const char* message_{};
	const Clock::time_point start_{};
};

