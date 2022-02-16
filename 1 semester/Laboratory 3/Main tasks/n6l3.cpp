#include <iostream>
using namespace std;
int main() {
	setlocale(LC_ALL, "Rus");
	int m = INT_MIN;
	int s = 0;
	int i1=0;
	cout << "Введите количество чисел" << endl;
	int n; cin >> n;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			int x; cin >> x;
			if ((x < 0) && (x % 7 == 0))
			{
				s = s + x;
				if (x > m)
				{
					m = x;
					i1 = i;
				}
			}

		}

		cout << "Сумма = " << s << " " << "Максимальное = " << m << " " << "Его номер - " << i1 + 1;
	}

	else
		cout << "Данные не подходят";

	return 0;
}