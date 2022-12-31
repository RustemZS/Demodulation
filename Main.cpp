// Подключение файлов
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
	std::cout << "Начало работы программы" << std::endl;
	FileManager anotherFile;

	// Ввод данных
	Input inFile("D:/Test work/Input.txt");

	// Считывание отсчётов сигнала из файла
	std::vector<Complex<float>> signal = anotherFile.loadFile(Input::getPath());
	std::vector<float> processedSignal(FileManager::getSize() / 2);

	// Демодуляция
	std::unique_ptr<Demodulator> demodulatorPtr(getPtr(FileManager::getModulation()));
	processedSignal = demodulatorPtr->demodulator(signal);

	// Фильтрация
	if (Input::isFilter())
		processedSignal = Filter::filter(processedSignal);
	
	// Передискретизация
	if (Input::isDownsample())
		processedSignal = downsample(processedSignal);

	// Вывод сигнала
	anotherFile.saveSignal(Input::getWavpath(), processedSignal);

	system("pause");
	return 0;
}
