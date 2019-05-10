#include "DecStr.hpp"
char* fun1(int num1, int num2)
{
    int A = num1 + num2;
    int modul, AS, i;
    AS = A;
    if (A < 0)
        A -= 2*A;
    modul = log10(A)+2;
    char *StrTmp = NULL;
    StrTmp = new char[modul];
    i = modul-1;
    for(; i>0;i--)
    {
        modul = A % 10;
        char x = modul + '0';
        StrTmp[i]= x;
        A /= 10;
    }
    if (AS < 0)
        StrTmp[0] = '-';
    else StrTmp[0]='+';
    return StrTmp;
    
}
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
    /*if (tmp.len >= pobj2.len)
    {
        
        int A = num1 + num2;
        int count = tmp.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    else
    {
        int A = num1 + num2;
        int count = pobj2.len + 1;
        int modul, AS, i = 0;
        AS = A;
        char *pMasCh = new char[count+1];
        pMasCh[count - 1] = '\0';
        while (i < count - 1)
            pMasCh[i++] = ' ';
        if (A < 0)
            A = -A;
        --i;
        while (A)
        {
            modul = A % 10;
            pMasCh[i] = modul + '0';
            A /= 10;
            --i;
        }
        if (AS < 0)
            pMasCh[i] = '-';
        pChTmp = pMasCh;
    }
    if (tmp.pCh)
        delete[] tmp.pCh;
    tmp.pCh = pChTmp;*/
    DecStr tmp(fun1(num1, num2));
    //tmp.len = strlen(pChTmp);
    //cout << pChTmp << endl;
    //cout << strlen(pChTmp) << endl;
    cout << "DecStr operator + (const DecStr &pobj1,const DecStr &pobj2)" << endl;
    return tmp;
}
DecStr operator + (const DecStr&pobj1, const char*pobj2){
    int num1, num2;
    //char *pChTmp;
    //DecStr tmp (pobj1);
    num1 = atoi(pobj1.getStr());
    num2 = atoi(pobj2);
    DecStr tmp(fun1(num1, num2));
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
    DecStr tmp(fun1(num1, num2));
    //tmp.len = strlen(pChTmp);
    //cout << pChTmp << endl;
    //cout << strlen(pChTmp) << endl;
    cout << "DecStr operator + (const DecStr &pobj1,const char* pobj2)" << endl;
    return tmp;
}
