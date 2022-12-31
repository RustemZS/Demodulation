#include "Complex.h"
#include "FileManager.h"

std::vector<float> downsample(const std::vector<float>& signal)
{
	Timer time;
	uint32_t copySize = 1 + (FileManager::getSize() / (FileManager::getParameterDown() * 2));
	if (FileManager::getSize() % (FileManager::getParameterDown() * 2) == 0)
	{
		copySize = FileManager::getSize() / (FileManager::getParameterDown() * 2);
	}

	std::vector<float> copy(copySize);
	uint32_t j = 0;
	for (uint32_t i = 1; i < FileManager::getSize() / 2; i += FileManager::getParameterDown())
	{
		copy[j] = signal[i];
		j++;
	}

	return copy;
}