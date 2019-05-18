

//
//  main.cpp
//  VPD
//
//  Created by Manh Tran on 12/02/2019.
//  Copyright © 2019 Manh Tran. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <math.h>
#include "Stroka.h"
#include "IdentStr.h"
#include "DecStr.h"
using namespace std;

//extern "C" char *__stdcall fun1(int);
int main(int argc, char *argv[])
{
	
     Stroka obj1("ITMO");
     obj1.Show();
     cout << obj1.getStr() << endl;
     Stroka obj2 = obj1;
     obj2.Show();
     Stroka obj3('z');
     obj3.Show();
     
    
     IdentStr obj4('k');
     obj4.Show();
     IdentStr obj5('5');
     obj5.Show();
     IdentStr obj6 = obj4;
     obj6.Show();
     IdentStr obj7("ITMO");
     obj7.Show();
     IdentStr obj8("_ITMO");
     obj8.Show();
     IdentStr obj9("1Itmo");
     obj9.Show();
     IdentStr obj10(";itmo");
     obj10.Show();
     IdentStr obj11("int");
     obj11.Show();
    
    IdentStr obj("ITMO");
    obj = obj + obj;
    obj.Show();
    
    char *pobj2 = "PBKS";
    DecStr obj41("10");
    DecStr obj31("190");
    obj41 = obj41 + obj31;
    obj41.Show();
    obj41 = "302" + obj41;
    obj41.Show();

    
    
    //IdentStr obj1();
    //obj1[2];
    //obj1.Show();

 
    //cout << "Zero char = " << obj1[2] << endl;
    
    //cout<< fun1(-2147483647)<<endl;
   // cout << endl;
    cout << "spaces in this filename\n" << endl;
	system("pause");
    return 0;
}

