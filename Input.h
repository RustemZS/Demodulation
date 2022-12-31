#ifndef INPUT_H
#define INPUT_H

#include <fstream>
#include <string>
#include <iostream>
#include "Timer.h"

struct Input {
	// ������ ����� � �������� �������
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
	static std::string path; // ���� � �����
	static std::string wavFile; // ���� � wav �����
	static int frequency; // ��������� ������� �������
	static bool needFilter; // ������� ��������� �������
	static bool filterType;  // ����� ���� �������
	static bool needDownsampling; // ������� ��������� �����������������
};

#endif