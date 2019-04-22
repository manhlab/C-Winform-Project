#ifndef Complex_H
#define Complex_H
#include "Stroka.h"
class Complex :public Stroka{
public:
	Complex(int = 0); // конструктор по умолчанию
	Complex(char*); // конструктор в который мы входим со строкой
	bool friend operator == (const Complex&, const Complex&); // переопределение оператора сравнения
	friend Complex operator + (const Complex&, const Complex&); // переопределение оператора сложения двух комплексных чисел
	~Complex(); // деструктор
	friend Complex operator + (const Complex&, const char*); // переопределение оператора сложения комплексного числа и строки
};
#endif Complex_H