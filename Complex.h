#ifndef COMPLEX_H
#define COMPLEX_H

#include <vector>
#include <math.h>
#define PI 3.14159

// ����������� ������
template <class T>
struct Complex {
	Complex()
	{
		re = 0;
		im = 0;
	}
	Complex(T re, T im)
	{
		this->re = re;
		this->im = im;
	}

	// ���������� ������ ������������ �����
	T abs()
	{
		return sqrt(re * re + im * im);
	}

	// ���������� ���� ������������ �����
	T arg()
	{
		return atan2(im, re);
	}

	// ���������� ���� ������������ ����� � ��������
	T argDeg()
	{
		return atan2(im, re) * 180/PI;
	}

private:
	T re;
	T im;
};

#endif