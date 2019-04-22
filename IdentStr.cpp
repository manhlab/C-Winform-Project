#include "IdentStr.h"
IdentStr::IdentStr(int val) : Stroka(val)
{
	cout << "IdentStr::IdentStr(int val) : Stroka(val), val=" << val << endl;
}
IdentStr::IdentStr(char Ch) : Stroka(Ch)
{
	if (((Ch >= 'a') && (Ch <= 'z')) || ((Ch >= 'A') && (Ch <= 'Z')))
	{
		len = 1;
		pCh = new char[2];
		pCh[0] = Ch;
		pCh[1] = '\0';
	}
	else
	{
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		cout << "Bad Symbol" << endl;
	}
}
IdentStr::IdentStr(char* Str) :Stroka(Str)
{
	if (pCh[0] >= 'a' && pCh[0] <= 'z' || pCh[0] >= 'A' && pCh[0] <= 'Z')
	{
	}
	else
	{
		cout << "Bad Symbol, pCh[0] =" << pCh[0] << endl;
		if (pCh) delete[] pCh;
		len = 0;
		pCh = new char[len + 1];
		pCh[0] = '\0';
		return;
	};
	for (int i(0); i < len; i++)
	{
		if ((pCh[i] >= 'a'&& pCh[i] <= 'z') || (pCh[i] >= 'A'&& pCh[i] <= 'Z') || (pCh[i] >= '0'&& pCh[i] <= '9') || pCh[i] == '_')
		{
			continue;
		}
		else
		{
			cout << "Bad stroka, pCh[" << i << "]=" << pCh[i] << endl;
			if (pCh) delete[] pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
}
IdentStr::IdentStr(const IdentStr& from) :Stroka(from)
{}
IdentStr::~IdentStr()
{}
IdentStr & IdentStr::operator = (const IdentStr& S)
{
	if (&S != this)
	{
		delete[] pCh;
		len = strlen(S.pCh);
		pCh = new char[len + 1];
		strcpy(pCh, S.pCh);
	}
	return *this;
}
int & IdentStr::operator () (char c)
{
	int k = -2;
	for (int i = 0; i<len; i++)
	if (c == pCh[i]) k = i;
	k++;
	return k;
}
/*char IdentStr::operator[](int index)
{
	return pCh[index];
}*/ 
bool operator == (const IdentStr&pobj1, const IdentStr&pobj2)
{
	if (pobj1.len != pobj2.len) return false;
	for (int i = 0; i<pobj1.len; i++)
	if (pobj1.pCh[i] != pobj2.pCh[i])
		return false;
	return true;
}
IdentStr & IdentStr::operator ~ (){
int i,j;
char tmp;
for(i=0; j= len-1; i<len/2; i++;j--}
{
	tmp = pCh[i];
	pCh[i] = pCh[j];
	pCh[j] = tmp;
}
cou<<"...."<<endl;
return *this;
}
IdentStr operator + (const IdentStr & pobj1, const IdentStr & pobj2)
{
	IdentStr tmp ;
	strcpy_s(pobj1, pobj1.GetLen(), tmp);
	int i = pobj1.GetLen();
	int j =0;
	while((tmp.pCh[i++]=pobj2.pCh[j++])){
		cout<<"..."<< endl;
		/* code */
	}
	return tmp;
}