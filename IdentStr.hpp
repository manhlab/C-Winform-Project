//
//  IdentStr.hpp
//  VPD
//
//  Created by Manh Tran on 28/03/2019.
//  Copyright © 2019 Manh Tran. All rights reserved.
//

#ifndef IdentStr_hpp
#define IdentStr_hpp

#include <iostream>
#include "Stroka.hpp"
using namespace std;
class IdentStr :public Stroka //производный класс - наследует данные-члены базового класса
{
public:
    IdentStr(int = 0);
    IdentStr(char ch);
    IdentStr(const char*);
    IdentStr(const IdentStr&);
    ~IdentStr();
    IdentStr& operator = (const IdentStr&);
    char& operator [] (int);
    IdentStr operator ~ ();
    friend IdentStr operator +(const IdentStr&, const IdentStr&);
    friend IdentStr operator +(const IdentStr&, const char*);
    friend IdentStr operator +(const char*, const IdentStr&);
    
};
#endif /* IdentStr_hpp */
