#include<cmath>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int A[10000];
	cout << " Сколько чисел?" << endl;
	int n; cin >> n;
	if (n > 1) {
		for (int i = 0; i < n; i++) {
			cin >> A[i];
			if (A[i] < 1) {
				cout << "Число не подходят условию" << endl;
				return 1;
			}
		}
		
		for (int j = 0; j < n; j++) {
			int p = 0;
			int count = 0;
			for (int d = 2; d <= (sqrt(A[j])+1); d++) {
				if (A[j] % d == 0) {
					count++;
				}
				if (count >= 1) {
					p++;
				}
			}
		
			if (p > 1) {
				for (int h = 0; h < n; h++) {
					for (int g = h + 1; g < n; g++)
						if ((A[h]) > (A[g]))
						{
							swap(A[h], A[g]);
						}
				}

				for (int i = 0; i < n; i++) {
					cout << A[i] << " ";
				}
				break;
			}

			else {
				cout << " Есть простые числа" << endl;
				break;
			}
		}
	}
	else
		cout << "Error";

	return 0;
}
