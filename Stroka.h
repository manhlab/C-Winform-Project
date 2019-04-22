#ifndef Stroka_H
#define Stroka_H
#pragma warning (disable : 4996)
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class Stroka
{
protected:
	int len; // длина
	char *pCh; // символьный массив (строка)
public:
	Stroka(int = 0); // конструктор по умолчанию
	Stroka(char*); // конструктор в который входим со строкой
	Stroka(const Stroka &); // конструктор в который входим с переменной типа Stroka
	~Stroka();
	char & operator [] (int); // поиск символа в строке по его индексу	
	Stroka & operator = (const Stroka &); // переопределение операции присваивания
	char* GetStr(void) { return pCh; } // функция по выводу (получению) строки
	int GetLen(void) { return len; } // функция по выводу (получению) строки
	void Show(void); // функция вывода
};
#endif Stroka_H