#include "Filter.h"

std::vector<float> Filter::filter(const std::vector<float>& inSignal)
{
	Timer time;
	std::vector<float> outSignal(FileManager::getSize() / 2);
	uint32_t window = (2 * Input::getFreq() / FileManager::getSamplingFreq());

	if (Input::isType())
	{
		// ������������� ������
		// window - ���������� �������� ��������� ����������
		std::cout << "�������� ������������� ������" << std::endl;
		float sumx = 0; // ����� �������� �� ���������
		for (uint32_t i = 0; i < FileManager::getSize() / 2; ++i) {
			uint32_t j = 0;
			while (i >= j)
			{
				sumx += inSignal[i - j];
				j++;
				if (j > window - 1)
				{
					j = i + 1;
				}

			}
			outSignal[i] = sumx / window;
			sumx = 0;
		}
	}
	else
	{
		// ����������� ������
		// window - ���������� �������� ��������� ����������
		std::cout << "�������� ����������� ������" << std::endl;
		float sumx = 0; // ����� �������� �� ���������
		float* mas; // ������ ��� �������� window ��������
		uint32_t index = 0; // ������ �������� �������
		mas = new float[window];
		for (uint32_t i = 0; i < window; ++i)
			mas[i] = 0;
		for (uint32_t i = 0; i < FileManager::getSize() / 2; ++i) {
			sumx -= mas[index];
			mas[index] = inSignal[i];
			sumx += mas[index];
			index++;
			if (index >= window)
				index = 0; // ������� � ������ "����"
			outSignal[i] = sumx / window;
		}
		delete[] mas;
	}
	return outSignal;
}