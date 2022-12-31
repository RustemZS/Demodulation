#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <string>
#include <fstream>

#include "Complex.h"
#include "Input.h"
#include "Wav.h"

// ���� ��������
struct FileManager {
		
	// ������ �����
	std::vector<Complex<float>> loadFile(const std::string& path);

	// ����� � ����
	void saveSignal(const std::string& wavFile, const std::vector<float>& signal);
	
	static int getSamplingFreq();

	static int getParameterDown();

	static uint32_t getSize();

	static std::string getModulation();

	private:
		static std::string modulation; // ��� ���������
		static int samplingFreq;	// ������� �������������
		static int parameterDown; // �������� �����������������
		static uint32_t size; // ������ �����
};

#endif