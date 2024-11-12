#pragma once
#include <chrono>
using namespace std;

class TimeService
{
private:
	chrono::time_point<chrono::steady_clock> previous_time;
	float delta_time;

	void UpdateDeltaTime();

	float CalculateDeltaTime();

	// Update previous_time to the current time
	void UpdatePreviousTime();

public:

	void Initialize();

	void Update();

	float GetDeltaTime();
};