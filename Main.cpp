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
	
	// ���������� AM
	if (Input::isFilter() && (FileManager::getModulation() == "AM"))
		signal = Filter<Complex<float>>::filter(signal);
	// �����������
	std::unique_ptr<Demodulator> demodulatorPtr(getPtr(FileManager::getModulation()));
	processedSignal = demodulatorPtr->demodulator(signal);
	
	// ���������� FM
	if (Input::isFilter() && (FileManager::getModulation() == "FM"))
		processedSignal = Filter<float>::filter(processedSignal);
	
	// �����������������
	if (Input::isDownsample())
		processedSignal = Downsampler<float>::downsample(processedSignal);
	
	// ����� �������
	anotherFile.saveSignal(Input::getWavpath(), processedSignal);

	system("pause");
	return 0;
}