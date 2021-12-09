#include<fstream>
#include <iostream>
using namespace std;
int main()
{
	const int N = 100;
	const int M = 100;
	setlocale(LC_ALL, "Rus");
	int A[N][M];
	int Proiz[N];
	ifstream in("input.txt");
	int n, m;
	int maxx = INT_MIN;
	int i1 = 0;
	in >> n >> m;
	//считывание матрицы с файла
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			in >> A[i][j];
		}

		Proiz[i] = 1;//инициализирование эл-ты произведения 1
	}
	//конец считывания
	//поиск макс. произведения
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Proiz[i] *= A[i][j];
		}
	}
	//поиск строки с макс.
	for (int i = 0; i < n; i++) {
		if (Proiz[i] > maxx) {
			maxx = Proiz[i];
			i1 = i;
		}
	}
	//замена строки максимумом
	for (int j = 0; j < m; j++) {
		A[i1][j] = maxx;
	}
	//вывод матрицы
	ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			out << A[i][j] << " ";
		out << endl;
	}
	
	out.close();
	return 0;
}