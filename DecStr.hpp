//
//  DecStr.hpp
//  VPD
//
//  Created by Manh Tran on 28/03/2019.
//  Copyright © 2019 Manh Tran. All rights reserved.
//

#ifndef DecStr_hpp
#define DecStr_hpp

#include <iostream>
#include "Stroka.hpp"
#include <cmath>
using namespace std;
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
#endif /* DecStr_hpp */
