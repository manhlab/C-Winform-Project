
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
	Stroka obj1("ITMO");
	Stroka massive[] = {"ITMO", 'k' , 5 , obj1};
	cout<< "Stroka operation"<<endl;
	for( int i = 0 ; i< sizeof(massive)/sizeof(massive[0]); i ++)
	{
		massive[i].Show();
	}
	IdentStr obj2 = "ITMO";
	IdentStr ident[] = {"ITMO", 'k' , 5 , obj2 };
	cout<< "Identify Stroka operation"<<endl;
	for( int i = 0 ; i< sizeof(ident)/sizeof(ident[0]); i ++)
	{
		ident[i].Show();
	}
    ident[3] = ident[1] + ident[0];
	ident[3] = ident[0] + "2019";
	ident[3] = "2019" + ident[0];
    ident[3].Show();
	cout<<(ident[3])[3]<<endl;
	cout<<(ident[3])['I']<<endl;
	
	DecStr obj3 = "1024";
	DecStr dec[] = {"312","+123","-112" , 5 , obj3 };
	cout<< "Stroka operation"<<endl;
	for( int i = 0 ; i< sizeof(dec)/sizeof(dec[0]); i ++)
	{
		dec[i].Show();
	}
	dec[2] = dec[1]+ dec[0];
	dec[2].Show();
	dec[2] = dec[1]+ "213";
	dec[2].Show();
	dec[2] = "213" + dec[1];
	dec[2].Show();
	dec[2] = dec[2]*2;
	dec[2].Show();
	dec[2] = 3*dec[2];
	dec[2].Show();
	dec[2] = dec[1]* dec[0];
	dec[2].Show();
	if(dec[2] == dec[3]) cout<<"equal the same string"<<endl;
	else cout<< "not equal"<<endl;
	
    cout<< fun2(-2147483647)<<endl;
   cout << endl;
    cout << "spaces in this filename\n" << endl;
	system("pause");
    return 0;
}

