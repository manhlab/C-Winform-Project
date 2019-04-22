#include "Stroka.h"
#include "IdentStr.h"
#include "Complex.h"
int main()
{
	setlocale(LC_ALL, "rus");
	Complex obj1("1i1");
	Complex obj2("13i14");
	Complex obj;
	bool b = (obj1 == obj2);
	cout << b << endl;
	obj = obj1 + obj2;

	cout << "Результат сложения: " << obj.GetStr() << endl << endl;
	int n;
	cout << "Введите количество комплексных чисел:" << endl;
	cin >> n;
	Stroka **array = new Stroka *[n];
	Complex obj3("0i0");
	for (int i(0); i < n; i++)
	{
		char* a = new char[100];
		cin >> a;
		array[i] = new Complex(a);
		delete[] a;
		obj3 = obj3 + *(Complex*)array[i];
	}
	cout << "сумма эл-тов:" << obj3.GetStr() << endl << endl;
	cout << "Введите количество строк:" << endl;
	cin >> n;
	Stroka **array1 = new Stroka *[n];
	for (int i(0); i < n; i++)
	{
		cout << "\nВведите строку: " << endl;
		char* a = new char[100];
		cin >> a;
		array1[i] = new IdentStr(a);
		delete[] a;
		char b;
		cout << "Введите cимвол: " << endl;
		cin >> b;
		int d = (*(IdentStr*)array1[i])(b);
		cout << "Индекс символа " << b << ": " << d << endl;
		int index;
		cout << "Введите индекс эл-та: " << endl;
		cin >> index;
		char c = (*array1[i])[index - 1];
		cout << "Символ под index = " << index << ": " << c << endl;

	}
	system("pause");
	return 0;
}
