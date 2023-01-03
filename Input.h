#ifndef INPUT_H
#define INPUT_H

#include <fstream>
#include <string>
#include <iostream>
#include "Timer.h"

struct Input {
	// Чтение файла с вводными данными
	Input(std::string start);

	static std::string getPath();

	static std::string getWavpath();

	static int getFreq();

	static bool isFilter();

	static bool isDownsample();

	static bool isType();

private:
	std::string data;
	std::string read;
	int intToBool;
	static std::string path; // Путь к файлу
	static std::string wavFile; // Путь к wav файлу
	static int frequency; // Граничная частота фильтра
	static bool needFilter; // Условие включения фильтра
	static bool filterType;  // Выбор типа фильтра
	static bool needDownsampling; // Условие включения передискретизации
};

#endif