//
// Created by RACA HAMA on 2019-05-18.
//

#ifndef UNTITLED_DECSTR_H
#define UNTITLED_DECSTR_H
#include <iostream>
#include "Stroka.h"

#include <cmath>
using namespace std;
//extern  "C" __stdcall char* fun1(int);
class DecStr: public Stroka
{
public:
    DecStr(int i=0);
    DecStr(const char*);
    //DecStr(const char);
    DecStr(const DecStr&);
    DecStr& operator = (const DecStr&);
    ~DecStr();
    friend DecStr operator + (const DecStr&, const DecStr&);
    friend DecStr operator + (const DecStr&, const char*);
    friend DecStr operator + (const char*, const DecStr&);
    friend bool operator == (const DecStr&, const DecStr&);
    char* fun1(int, int);


};
#endif //UNTITLED_DECSTR_H
