#pragma once
#include <chrono>
using namespace std;

static class TimeService
{
private:
	static chrono::time_point<chrono::steady_clock> previous_time;
	static float delta_time;

	static void updateDeltaTime()
	{
		delta_time = calculateDeltaTime();
		updatePreviousTime();
	}

	static float calculateDeltaTime()
	{
		// Calculate time difference in microseconds between the current and previous frame.
		int delta = std::chrono::duration_cast<std::chrono::microseconds>(
			std::chrono::steady_clock::now() - previous_time).count();

		// To convert delta time from microseconds into seconds.
		return static_cast<float>(delta) / static_cast<float>(1000000);
	}

	// Update previous_time to the current time
	static void updatePreviousTime()
	{
		previous_time = std::chrono::steady_clock::now();
	}

public:

	static void initialize()
	{
		previous_time = std::chrono::steady_clock::now();
		delta_time = 0;
	}

	static void update()
	{
		updateDeltaTime();
	}

	static float getDeltaTime()
	{
		return delta_time;
	}
};