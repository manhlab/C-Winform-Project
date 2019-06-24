//
// Created by RACA HAMA on 2019-05-18.
//

#include "DecStr.h"
extern "C" char* __stdcall fun2(int);
char* fun1(int num1)
{
    int A = num1 ;
    int modul, AS, i;
    AS = A;
    if (A < 0)
        A -= 2*A;
    modul = log10(static_cast<double> (A))+2;
	char *p = new char[];
	*(p + modul) = '\0';
    i = modul-1;
    for(; i>0;i--)
    {
        modul = A % 10;
        *(p + i) = modul + '0';
        A /= 10;
    }
    if (AS < 0)
        *p  = '-';
    else *p = '+';
    return p;
};
DecStr:: DecStr (int val): Stroka (val)
{
    cout << "DecStr::DecStr(int val): Stroka (val)" << val << endl;
}
DecStr::DecStr (const char *dstr):Stroka(dstr)
{
    if (!((pCh[0] >= '1' && pCh[0] <= '9') || (pCh[0] == '-' && pCh[1] >='1' && pCh[1] <='9') || pCh[0]=='+'|| pCh[0]==' '))
    {
        cout << "bad symbol, pCh[0]=" << pCh[0] << endl;
        if (pCh)
            delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
    }
	for (int i = 1; i<len;i++)
	{
		if (!(pCh[0] >= '1' && pCh[0] <= '9'))
		{
		cout << "bad symbol, pCh[0]=" << pCh[0] << endl;
        if (pCh)
            delete[] pCh;
        len = 0;
        pCh = new char[len + 1];
        pCh[0] = '\0';
        return;
		}
	}
    cout << "DecStr::DecStr (const char *dstr):Stroka(dstr)" << endl;
}

DecStr :: DecStr (const DecStr &from): Stroka (from)
{
    cout << "DecStr::DecStr (const DecStr &from): Stroka (from)" << endl;
}

DecStr :: ~DecStr()
{
    cout << "DecStr::~DecStr()" << endl;
}

DecStr & DecStr :: operator = (const DecStr &dS)
{
    if(&dS!=this)
    {
        delete[] pCh;
        len = strlen(dS.pCh);
        pCh = new char[len + 1];
        strcpy(pCh,dS.pCh);
    }
    cout << "DecStr & DecStr :: operator = (const DecStr &dS)" << endl;
    return *this;
}
DecStr operator + (const DecStr &pobj1,const DecStr &pobj2)
{
    int num1, num2;
    //char *pChTmp;
    //DecStr tmp (pobj1);
    num1 = atoi(pobj1.getStr());
    num2 = atoi(pobj2.getStr());
    num1 = num1+ num2;
	DecStr tmp(fun2(num1));
	
    cout << "DecStr operator + (const DecStr &pobj1,const DecStr &pobj2)" << endl;
    return tmp;
}

DecStr operator + (const DecStr &pobj1,int num)
{
    int num1;
    //char *pChTmp;
    //DecStr tmp (pobj1);
    num1 = atoi(pobj1.getStr());
    num1 = num1+ num;
	DecStr tmp(fun1(num1));
    cout << "DecStr operator + (const DecStr &pobj1,const int num)" << endl;
    return tmp;
}
DecStr operator + ( int num,const DecStr &pobj2)
{
    int num1; 
    //char *pChTmp;
    //DecStr tmp (pobj1);
    
    num1 = atoi(pobj2.getStr());
    num1 = num1+ num;
	DecStr tmp(fun1(num1));
    cout << "DecStr operator + (const int num,const DecStr &pobj2)" << endl;
    return tmp;
}
DecStr operator + (const DecStr&pobj1, const char*pobj2){
    int num1, num2;
    //char *pChTmp;
    //DecStr tmp (pobj1);
    num1 = atoi(pobj1.getStr());
    num2 = atoi(pobj2);
	num1 += num2;
    //DecStr tmp(fun1(num1));
	DecStr tmp(fun1(num1));
    //tmp.len = strlen(pChTmp);
    //cout << pChTmp << endl;
    //cout << strlen(pChTmp) << endl;
    cout << "DecStr operator + (const DecStr &pobj1,const char* pobj2)" << endl;
    return tmp;
}
DecStr operator + (const char*pobj1, const DecStr &pobj2){
    int num1, num2;
    //char *pChTmp;
    //DecStr tmp (pobj1);
    num1 = atoi(pobj1);
    num2 = atoi(pobj2.getStr());
	num1 += num2;
    //DecStr tmp(fun1(num1));
	DecStr tmp(fun1(num1));
    //tmp.len = strlen(pChTmp);
    //cout << pChTmp << endl;
    //cout << strlen(pChTmp) << endl;
    cout << "DecStr operator + (const DecStr &pobj1,const char* pobj2)" << endl;
    return tmp;
}
bool operator==(const DecStr& left, const DecStr& right)
{ if (left.getLen() != right.getLen())
	return false;
	const char* lStr = left.getStr(); 
	const char* rStr = right.getStr();
	for (int i = 0; i < left.getLen(); i++) 
		if (*lStr++ != *rStr++)
	return false;
}
DecStr operator * (const int s, const DecStr& pobj1)
{

	int number  = atoi(pobj1.getStr());
	number *= s;
	DecStr tmp(fun2(number));
	cout << "DecStr operator * (const int s, const DecStr& pobj1)" << endl;
	return tmp;

}
DecStr operator * (const DecStr& pobj1,const int s)
{
	int number  = atoi(pobj1.getStr());
	number *= s;
	DecStr tmp(fun1(number));
	cout << "DecStr operator * (const DecStr& pobj1,const int s)" << endl;
	return tmp;
}
DecStr operator * (const DecStr& pobj1,const DecStr& pobj2)
{
	
	int num1  = atoi(pobj1.getStr());
	int num2  = atoi(pobj2.getStr());
	num1 *= num2;
	DecStr tmp(fun1(num1));
	cout << "DecStr operator * (const DecStr& pobj1,const DecStr& pobj2)" << endl;
	return tmp;
	
}

