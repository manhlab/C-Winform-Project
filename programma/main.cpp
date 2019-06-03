
#include <iostream>
#include <string.h>
#include <math.h>
#include "Stroka.h"
#include "IdentStr.h"
#include "DecStr.h"
using namespace std;
extern "C" char* __stdcall fun2(int);
int main(int argc, char *argv[])
{
	/*
	Stroka obj1 = "ITMO";
	Stroka *pMas[12];
	pMas[0] = new Stroka("2019");
	pMas[1] = new Stroka('k');
	pMas[2] = new Stroka(5);
	pMas[3] = new Stroka(obj1);
	pMas[4] = new IdentStr("ITMO");// contructor char*
	pMas[5] = new IdentStr(*((IdentStr*)pMas[4]));// contrustor &
	pMas[6] = new IdentStr('k');// char contructor
	pMas[7] = new IdentStr(5);// int contructor
	cout<<(*(IdentStr*)pMas[4])[3]<<endl;//index number
	cout<<(*(IdentStr*)pMas[4])['I']<<endl;// first index number
	pMas[8] = new DecStr("312");// consrustir with string num
	pMas[9] = new DecStr(*(DecStr*)pMas[8]);// constructor copy obj
	pMas[10] = new DecStr("-312");// with - 
	pMas[11] = new DecStr("2019");// normal string number
	*(DecStr*)pMas[11] = *(DecStr*)pMas[8] + *(DecStr*)pMas[9];// + 2 obj
	//*(DecStr*)pMas[11] = *(DecStr*)pMas[8] + "123";// obj+ string

	*(DecStr*)pMas[10] = *(DecStr*)pMas[8] + 123;// obj+ num
	*(DecStr*)pMas[10] = 123 + *(DecStr*)pMas[8];//num+obj

	*(DecStr*)pMas[10] = "-123" + *(DecStr*)pMas[8];// - num + obj
	*(DecStr*)pMas[8] = *(DecStr*)pMas[8]*2;// obj*int
	*(DecStr*)pMas[8] = 2*(*(DecStr*)pMas[8]);//int *obj
	*(DecStr*)pMas[8] = *(DecStr*)pMas[8] *(*(DecStr*)pMas[8]);//obj*obj
	for ( int i = 0; i< sizeof(pMas)/sizeof(pMas[0]); i++)
	{
		cout<<"value of pMas["<<i<<"]"<<endl;
		pMas[i]->Show();
	}
	pMas[11]->Show();
	if(*(DecStr*)pMas[11] == *(DecStr*)pMas[10]) cout<<"equal the same string"<<endl;
	else cout<< "not equal"<<endl;
	for ( int i = 0; i< sizeof(pMas)/sizeof(pMas[0]); i++)
	{
		delete pMas[i];
	}
	cout<< fun1(-2147483627)<<endl;
	DecStr obj1;
    DecStr obj3(fun1(-2147483647));
	DecStr obj4(fun2(+83646));
	//obj1 =  obj3+obj4;
	obj1 =   255+ obj4;*/
	IdentStr obj1("BIT");
	IdentStr obj2("ITMO");
	obj2 =  obj2 + "2019";
	obj2 = "K2019" + obj1;
	

	cout << "index of '2' element of string: "<< obj2['I']<<endl<< "2rd element: " << obj2[2] << endl;
	obj2.Show();
	cout << endl;
    cout << "spaces in this filename\n" << endl;
	system("pause");
    return 0;
}

