#ifndef DOWNSAMPLE_H
#define DOWNSAMPLE_H

#include "Complex.h"
#include "FileManager.h"

// Передискретизация
template <class T>
struct Downsampler {
	static std::vector<T> downsample(const std::vector<T>& signal)
	{
		Timer time;
		uint32_t copySize = 1 + (signal.size() / (FileManager::getParameterDown()));
		if (signal.size() % (FileManager::getParameterDown()) == 0)
		{
			copySize = signal.size() / (FileManager::getParameterDown());
		}

		std::vector<T> copy(copySize);
		uint32_t j = 0;
		for (uint32_t i = 1; i < signal.size(); i += FileManager::getParameterDown())
		{
			copy[j] = signal[i];
			j++;
		}

		return copy;
	}
};

#endif