#include "Complex.h"
Complex::Complex(int val) : Stroka(val)
{
	cout << "Complex::Complex(int val) : Stroka(val)" << endl;
};
Complex::~Complex()
{
};
Complex::Complex(char*Str) : Stroka(Str)
{
	int k = 0;
	for (int i(0); i < len; i++)
	{
		if (((i == 0) && ((pCh[i] == '+') || (pCh[i] == '-') || (pCh[i] >= '0' && pCh[i] <= '9'))) ||
			((i>0) && ((pCh[i] >= '0' && pCh[i] <= '9') || pCh[i] == 'i') && (k <= 1)) ||
			((i>0 && i<len - 1) && (pCh[i - 1] == 'i') && ((pCh[i] == '+') || (pCh[i] == '-') || (pCh[i] >= '0' && pCh[i] <= '9'))) ||
			((i == len - 1) && (pCh[i - 1] == 'i') && ((pCh[i] >= '0' && pCh[i] <= '9'))))
		{
			if (pCh[i] == 'i')
				k++;
			if (k > 1)
			{
				if (pCh) delete[] pCh;
				len = 0;
				pCh = new char[len + 1];
				pCh[0] = '\0';
				return;
			}
		}
		else
		{
			if (pCh) delete[] pCh;
			len = 0;
			pCh = new char[len + 1];
			pCh[0] = '\0';
			return;
		}
	}
};


bool operator == (const Complex &pobj1, const Complex &pobj2)
{
	char* pCh1 = new char[100];
	char* pCh2 = new char[100];
	char* pCh3 = new char[100];
	char* pCh4 = new char[100];
	int Re1 = 0, Re2 = 0, Im1 = 0, Im2 = 0;
	int i = 0;
	int j = 0;
	if (pobj1.pCh[0] != '\0' || pobj2.pCh[0] != '\0')
	{
		while (pobj1.pCh[i] != 'i')
		{
			pCh1[j] = pobj1.pCh[i];
			i++;
			j++;
		}
		i++;
		j = 0;
		while (i < pobj1.len)
		{
			pCh2[j] = pobj1.pCh[i];
			i++;
			j++;
		}
		Re1 = std::atoi(pCh1);
		Im1 = std::atoi(pCh2);
		i = 0;
		j = 0;
		while ((pobj2.pCh[i] != 'i') && (i < pobj2.len))
		{
			pCh3[j] = pobj2.pCh[i];
			i++;
			j++;
		}
		i++;
		j = 0;
		while (i < pobj2.len)
		{
			pCh4[j] = pobj2.pCh[i];
			i++;
			j++;
		}
		Re2 = atoi(pCh3);
		Im2 = atoi(pCh4);
	}
	cout << "Первое комплексное число " << endl;
	if (pobj1.pCh[0] == '\0')
	{
		Re1 = 0; Im1 = 0;
		cout << "Ведены неверные данные" << endl;
	}
	else
		cout << Re1 << "i" << Im1 << endl << endl;
	cout << "Bторое комплексное число" << endl;
	if (pobj2.pCh[0] == '\0')
	{
		Re2 = 0; Im2 = 0;
		cout << "Введены неверные данные" << endl;
	}
	else
		cout << Re2 << "i" << Im2 << endl << endl;
	bool a = false;
	if (Re1 == Re2 && Im1 == Im2) a = true;
	cout << "Результат сравнения:" << endl;
	return a;
}
Complex operator + (const Complex &pobj1, const Complex &pobj2)
{
	char* pCh1 = new char[pobj1.len];
	char* pCh2 = new char[pobj1.len];
	char* pCh3 = new char[pobj2.len];
	char* pCh4 = new char[pobj2.len];
	char bufRe[100], bufIm[100];
	char* pobj = new char[100];
	int Re1 = 0, Re2 = 0, Im1 = 0, Im2 = 0;
	int i = 0, j = 0;
	int Re = 0, Im = 0, Summ = 0;
	if (pobj1.pCh[0] != '\0' || pobj2.pCh[0] != '\0')
	{
		while (pobj1.pCh[i] != 'i' && i<pobj1.len)
		{
			pCh1[j] = pobj1.pCh[i];
			i++; j++;
		}
		i++;
		j = 0;
		while (i < pobj1.len)
		{
			pCh2[j] = pobj1.pCh[i];
			i++; j++;
		}
		i = 0; j = 0;
		Re1 = atoi(pCh1);
		Im1 = atoi(pCh2);
		while (pobj2.pCh[i] != 'i' && i<pobj2.len)
		{
			pCh3[j] = pobj2.pCh[i];
			i++; j++;
		}
		i++;
		j = 0;
		while (i < pobj2.len)
		{
			pCh4[j] = pobj2.pCh[i];
			i++;
			j++;
		}
		Re2 = atoi(pCh3);
		Im2 = atoi(pCh4);
	}
	else
	{
		Re1 = 0; Im1 = 0; Re2 = 0; Im2 = 0; Re = 0; Im = 0;
		char *pRe = itoa(Re, bufRe, 10);
		char *pIm = itoa(Im, bufIm, 10);
		cout << "Введены неверные данные" << endl << endl;
	}
	__asm
	{
		mov EAX, Re1
			mov EBX, Re2
			add EAX, EBX
			mov Re, EAX
			mov EAX, Im1
			mov EBX, Im2
			add EAX, EBX
			mov Im, EAX
	};
	char *pRe = itoa(Re, bufRe, 10);
	char *pIm = itoa(Im, bufIm, 10);
	int k = 0;
	for (int i(0); i < strlen(pRe); i++, k++)
		pobj[k] = pRe[i];
	pobj[k] = 'i';
	k++;
	for (int i(0); i < strlen(pIm); i++, k++)
		pobj[k] = pIm[i];
	pobj[k] = '\0';
	if (pCh1) delete[] pCh1;
	if (pCh2) delete[] pCh2;
	if (pCh3) delete[] pCh3;
	if (pCh4) delete[] pCh4;
	return pobj;
};