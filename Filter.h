#ifndef FILTER_H
#define FILTER_H

#include "Complex.h"
#include "FileManager.h"
#include "Input.h"

// ������ ����������� ��������
struct Filter {
	static std::vector<float> filter(const std::vector<float>& inSignal);
};

#endif