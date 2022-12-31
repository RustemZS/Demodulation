#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <iostream>

class Timer
{
public:
	Timer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		stop = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = stop - start;
		std::cout << ":: Время выполнения " << duration.count() << " с ::" << std::endl;
	}
private:
	std::chrono::time_point<std::chrono::steady_clock> start, stop;
};

#endif

