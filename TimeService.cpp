#include "TimeService.h"

void TimeService::UpdateDeltaTime()
{
	delta_time = CalculateDeltaTime();
	UpdatePreviousTime();
}

float TimeService::CalculateDeltaTime()
{
	// Calculate time difference in microseconds between the current and previous frame.
	int delta = std::chrono::duration_cast<std::chrono::microseconds>(
		std::chrono::steady_clock::now() - previous_time).count();

	// To convert delta time from microseconds into seconds.
	return static_cast<float>(delta) / static_cast<float>(1000000);
}

// Update previous_time to the current time
void TimeService::UpdatePreviousTime()
{
	previous_time = std::chrono::steady_clock::now();
}

void TimeService::Initialize()
{
	previous_time = std::chrono::steady_clock::now();
	delta_time = 0;
}

void TimeService::Update()
{
	UpdateDeltaTime();
}

float TimeService::GetDeltaTime()
{
	return delta_time;
}