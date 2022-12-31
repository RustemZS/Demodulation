#ifndef COMPLEX_H
#define COMPLEX_H

#include <vector>
#include <math.h>
#define PI 3.14159

// Комплексный отсчёт
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

	// Нахождение модуля комплексного числа
	T abs()
	{
		return sqrt(re * re + im * im);
	}

	// Нахождение фазы комплексного числа
	T arg()
	{
		return atan2(im, re);
	}

	// Нахождение фазы комплексного числа в градусах
	T argDeg()
	{
		return atan2(im, re) * 180/PI;
	}

private:
	T re;
	T im;
};

#endif