// ����������� ������
#include "Complex.h"
#include "Input.h"
#include "FileManager.h"
#include "Filter.h"
#include "Downsample.h"
#include "Demodulator.h"
#include "Timer.h"

int main()
{
	Timer timer;
	setlocale(LC_ALL, "ru-RU");
	std::cout << "������ ������ ���������" << std::endl;
	FileManager anotherFile;

	// ���� ������
	Input inFile("D:/Test work/Input.txt");

	// ���������� �������� ������� �� �����
	std::vector<Complex<float>> signal = anotherFile.loadFile(Input::getPath());
	std::vector<float> processedSignal(FileManager::getSize() / 2);

	// �����������
	std::unique_ptr<Demodulator> demodulatorPtr(getPtr(FileManager::getModulation()));
	processedSignal = demodulatorPtr->demodulator(signal);

	// ����������
	if (Input::isFilter())
		processedSignal = Filter::filter(processedSignal);
	
	// �����������������
	if (Input::isDownsample())
		processedSignal = downsample(processedSignal);

	// ����� �������
	anotherFile.saveSignal(Input::getWavpath(), processedSignal);

	system("pause");
	return 0;
}