#ifndef IdentStr_H
#define IdentStr_H
#include "Stroka.h"
class IdentStr : public Stroka
{
public:
	IdentStr(int = 0); // конструктор по умолчанию
	IdentStr(char ch); // конструктор в который входим с одним символом
	IdentStr(char*); // конструктор в который входим со строкой
	IdentStr(const IdentStr &); // конструктор в который входим с переменной типа IdentStr
	~IdentStr(); // деструктор
	bool friend operator == (const IdentStr&, const IdentStr&); // переопределение оператора сравнения
	IdentStr & operator = (const IdentStr &); // переопределение оператора присваивания
	int & operator () (char); // поиск индекса элемента в строке по символу
	//char operator [] (int);
};
#endif IdentStr_H