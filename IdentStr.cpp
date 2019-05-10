//
//  IdentStr.cpp
//  VPD
//
//  Created by Manh Tran on 28/03/2019.
//  Copyright © 2019 Manh Tran. All rights reserved.
//

#include "IdentStr.hpp"
IdentStr::IdentStr(int val) :Stroka(val)
{
    cout << "IdentStr::IdentStr(int val):Stroka(val),val=" << val << endl;
}

IdentStr::IdentStr(char Ch) : Stroka(Ch)
{
    if (!((pCh[0] >= 'a' && pCh[0] <= 'z') || (Ch >= 'A' && Ch <= 'Z')))
    {
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        cout << "Bad Symbol" << endl;
    }
    cout << "IdentStr::IdentStr(char Ch):Stroka(Ch)" << endl;
}

IdentStr::IdentStr(const IdentStr& from) :Stroka(from)
{
    //strcpy(pCh,from.pCh);
    cout << "IdentStr::IdentStr(const IdentStr& from): Stroka(from)" << endl;
}

//checker for system words with letters
IdentStr::IdentStr(const char* Str) :Stroka(Str)
{
    const char* systemw[] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "asm", "bool", "catch", "class", "const_cast", "delete", "dynamic_cast", "explicit", "export", "false", "friend", "inline", "mutable", "namespace", "new", "operator", "private", "protected", "public", "reinterpret_cast", "static_cast", "template", "this", "throw", "true", "try", "typeid", "typename", "using", "virtual", "wchar_t", "_Bool", "_Complex", "_Imaginary", "restrict" };
    if ((pCh[0] >= '0' && pCh[0] <= '9') || (pCh[0] == ' ') || (pCh[0] == ';'))
    {
        cout << "Bad Stroka pCh[0]=" << pCh[0] << endl;
        if (pCh) delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
    for (int i = 1; i < len; i++)
    {
        if (!((pCh[i] >= 'a' && pCh[i] <= 'z') || (pCh[i] >= 'A' && pCh[i] <= 'Z') || (pCh[i] >= '0' && pCh[i] <= '9') || (pCh[i] == '_')))
        {
            cout << "Bad Stroka pCh[0]=" << pCh[0] << endl;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    for (int i = 0; i < 67; i++)
    {
        if (!strcmp(pCh, systemw[i]))
        {
            cout << "Warning! System word: " << pCh << endl;
            if (pCh) delete[] pCh;
            len = 0;
            pCh = new char[len + 1];
            pCh[0] = '\0';
            return;
        }
    }
    cout << "IdentStr::IdentStr(const char* Str):Stroka(Str)" << endl;
    return;
}
//end of checker for system words with letters

IdentStr::~IdentStr()
{
    cout << "IdentStr::~IdentStr()" << endl;
}

IdentStr& IdentStr::operator=(const IdentStr& S)
{
    if (&S != this)
    {
        delete[] pCh;
        len = (int)strlen(S.pCh);
        pCh = new char[len + 1];
        strcpy(pCh, S.pCh);
    }
    cout << "IdentStr& IdentStr::operator=(const IdentStr& S)" << endl;
    return *this;
}
IdentStr operator + (const IdentStr&obj1, const IdentStr&obj2)
{
    IdentStr tmp(obj1.getLen() + obj2.getLen());
    int i = 0;
    int j=0;
    //strcat(tmp.pCh, obj2.GetStr());
    //int i = obj1.getLen();
    //int j = 0;
    while ((tmp.pCh[i++] = obj1.pCh[j++]));
    --i;
    j=0;
    while((tmp.pCh[i++]=obj2.pCh[j++])){
        cout<<"IdentStr operator + (const IdentStr & pobj1, const IdentStr & pobj2)"<< endl;
        /* code */
    }
    return tmp;
}


IdentStr operator + (const IdentStr &obj1, const char *obj2)
{
    IdentStr tmp(obj1.getLen() + (int)strlen(obj2));
    //strcpy(tmp.pCh, obj1.GetStr());
    int i = 0;
    int j=0;
    //strcat(tmp.pCh, obj2.GetStr());
    //int i = obj1.getLen();
    //int j = 0;
    while ((tmp.pCh[i++] = obj1.pCh[j++]));
    --i;
    j=0;
    while((tmp.pCh[i++] = *obj2++));
    cout << "IdentStr operator + (const IdentStr&obj1, const char&obj2)" <<endl;
    return tmp;
};
IdentStr operator + (const char *obj1, const IdentStr &obj2)
{
    IdentStr tmp((int)strlen(obj1) + obj2.getLen());
    //strcpy(tmp.pCh, obj1.GetStr());
    int i = 0;
    int j=0;
    //strcat(tmp.pCh, obj2.GetStr());
    //int i = obj1.getLen();
    //int j = 0;
    while ((tmp.pCh[i++] = *obj1++));
    --i;
    j=0;
    while((tmp.pCh[i++] = obj2.pCh[j++]));
    cout << "IdentStr operator + (const char*obj1, const IdentStr&obj2)" <<endl;
    return tmp;
};


IdentStr IdentStr::operator ~ ()
{
    int i, j;
    char tmp;
    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        tmp = pCh[i];
        pCh[i] = pCh[j];
        pCh[j] = tmp;
    }
    cout << "IdentStr& IdentStr:operator ~ ()" << endl;
    return *this;
}

char& IdentStr::operator [] (int Index)
{
    if (Index >= 0 && Index < len)
    {
        cout << "char& IdentStr::operator [] (int Index)" << endl;
        return pCh[Index];
    }
    return pCh[0];
}
