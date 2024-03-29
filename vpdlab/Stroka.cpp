//
// Created by RACA HAMA on 2019-05-18.
//

#include "Stroka.h"
Stroka::Stroka(int val) :len(val), pCh(new char[len + 1]) //конструктор длина строки
{
    if (val == 0) pCh[0] = '\0';
	else pCh[val]='\0';
    cout << "Stroka::Stroka(int val):len= " << len << endl;
}

Stroka::Stroka(char ch) :len(1), pCh(new char[len + 1]) //конструктор символ
{
    pCh[0] = ch;
    pCh[1] = '\0';
    cout << "Stroka::Stroka(char ch)" << endl;
}

Stroka::Stroka(const char* s) : len(strlen(s)), pCh(new char[len + 1]) //конструктор строка
{
    strcpy(pCh, s);
    cout << "Stroka::Stroka(const char* s)" << endl;
}

Stroka::Stroka(const Stroka& from) :len(strlen(from.pCh)), pCh(new char[from.len + 1]) //конструктор копирование
{
    strcpy(pCh,  from.pCh);
    cout << "Stroka::Stroka(const Stroka& from)" << endl;
}

Stroka::~Stroka()    //деструктор
{
    if (pCh) delete[]pCh;
    cout << "Stroka::~Stroka()" << endl;
}

void Stroka::Show(void)
{
    cout << "len = " << len << endl;
	cout << "pCh = " << pCh<< endl;
}
