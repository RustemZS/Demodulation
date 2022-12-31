#ifndef DEMODULATOR_H
#define DEMODULATOR_H

#include "Complex.h"
#include "FileManager.h"
#include "Input.h"

// Интерфейс демодулятора
struct Demodulator {
	virtual std::vector<float> demodulator(const std::vector<Complex<float>>& signal) = 0;
	virtual ~Demodulator() {}
};

// Амплитудный демодулятор
struct DemodulatorAM : Demodulator {
	std::vector<float> demodulator(const std::vector<Complex<float>>& signal) override
	{
		Timer time;
		std::cout << "Работает DemodulatorAM" << std::endl;
		result.resize(FileManager::getSize() / 2);
		for (uint32_t i = 0; i < FileManager::getSize() / 2; ++i)
		{
			sample = signal[i];
			sum += sample.abs();
			result[i] = sample.abs();
		}
		mean = 2 * sum / FileManager::getSize();
		for (uint32_t i = 0; i < FileManager::getSize() / 2; ++i)
		{
			result[i] -= mean;
		}

		return result;
	}
	~DemodulatorAM() {}
private:
	float sum = 0;
	float mean = 0;
	Complex<float> sample;
	std::vector<float> result;
};

// Частотный демодулятор
struct DemodulatorFM : Demodulator {
	std::vector<float> demodulator(const std::vector<Complex<float>>& signal) override
	{
		Timer time;
		std::cout << "Работает DemodulatorFM" << std::endl;
		result.resize(FileManager::getSize() / 2);

		for (uint32_t i = 0; i < FileManager::getSize() / 2; ++i)
		{
			sample = signal[i];
			phase = sample.arg();
			
			if (i == 0)
			{
				result[i] = phase * FileManager::getSamplingFreq();
			}
			else
			{
				samplePast = signal[i-1];
				phasePast = samplePast.arg();
				razn = phase - phasePast;
				while ((razn > PI/2) || (razn < -1 * PI/2))
				{
					if (razn > PI/2)
						razn -= PI;
					else
						razn += PI;
				}
				result[i] = razn * FileManager::getSamplingFreq();
			}
		}

		return result;
	}
	~DemodulatorFM() {}

private:
	float phase = 0;
	float phasePast = 0;
	float razn = 0;
	Complex<float> sample;
	Complex<float> samplePast;
	std::vector<float> result;
};

Demodulator* getPtr(const std::string& modulation)
{
	Demodulator* ptr = new DemodulatorAM;
	if (modulation == "AM")
	{
		return ptr;
	}
	else if (modulation == "FM")
	{
		ptr = new DemodulatorFM;
		return ptr;
	}
	
}

#endif
