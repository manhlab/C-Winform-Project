//
//  Stroka.hpp
//  VPD
//
//  Created by Manh Tran on 28/03/2019.
//  Copyright © 2019 Manh Tran. All rights reserved.
//

#ifndef Stroka_hpp
#define Stroka_hpp

#include <iostream>
using namespace std;
class Stroka
{
protected:
    int len;
    char* pCh;
public:
    
    Stroka(int = 0); //конструктор по умолчанию
    Stroka(char ch);
    Stroka(const char*);
    Stroka(const Stroka&);
    ~Stroka();
    char* getStr(void)const
    {
        return pCh;
    }
    int getLen(void)const
    {
        return len;
    }
    void Show(void);
};
#endif /* Stroka_hpp */
