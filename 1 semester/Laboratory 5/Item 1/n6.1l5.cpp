#include<fstream>
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	char c[100];
	int i1 = 0; int x;
	cout << "Введите строку" << endl;
	cin.getline(c, 100);
	cout << "Что ищем?" << endl;
	char n; cin.get(n);
	for (int i = 0; i < strlen(c); i++) 
	{
		if (c[i] == n)
		{
			i1++;
			x = i + 1;
			break;
		}
		
	}
	if (i1 ==1 )
	{
		cout << "Такой символ есть, его номер = " << x << endl;
	}
	else
	{
		cout << "Такого символа нет" << endl;
	}

}
