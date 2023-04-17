#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//int GetStroka(char x)
//{
//	if (x == 'a')
//		return 1;
//	else if (x == 'b')
//		return 2;
//	else if (x == 'c')
//		return 3;
//}
//int FindSost( char c)
//{
//	for (int i = 0; i < n; i++)
//		if (mas[0][i] == c)
//			return i;
//}
//void write()
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			cout << mas[i][j] << " ";
//		cout << endl;
//	}
//}
//void Proverka( int F)
//{
//	string str;
//	getline(cin, str);
//	int x = 0, y = 0;
//
//	x = GetStroka(str[0]); y = 1;
//	cout << "mas = " << mas[x][y] << endl;
//	str.erase(0, 1);
//	cout << "str = " << str;
//	while (!str.empty() && mas[x][y] != '0')
//	{
//		y = FindSost(mas[x][y]);
//		x = GetStroka(str[0]);
//		cout << "mas = " << mas[x][y] << endl;
//		str.erase(0, 1);
//		cout << "str = " << str;
//	}
//	//for (int i = 0; i < F.size(); i++)
//	{
//		if (str.empty() && mas[x][y] == 'F')
//			cout << "OK! - " << F << endl;
//		else
//			cout << "No - " << F << endl;
//	}
//}
string Count(string q)
{
	string time = "";
	for (int i = 0; i < q.length(); i++)
		if (time.find(q[i]) == string::npos)
			time += q[i];

	return time;
}
void write(int** mas, int n, int m)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
int num_q(int i, string q)
{
	/*if (Count(q).find(q[i]) == string::npos)
		return 0;
	else*/
	return Count(q).find(q[i]);
}

void init_mas(int** mas, string q, int m)
{	
	int len = 0;	

	for (int j = 0; j < m; j++)
		mas[0][j] = 0;
	mas[0][num_q(0, q)] = 1;
	//write(mas, q.length()+1, m);

	for (int i = 1; i < q.length() + 1; i++)
	{	
		mas[i] = mas[len];
		cout << "\n \n \t \t Copy from " << len << " to " << i;
		write(mas, q.length()+1, m);

		cout << "in " << i << " " <<  num_q(i, q) << endl;
		mas[i][Count(q).find(q[i])] = i + 1;
		cout <<" mas[i][j] = " << mas[i][Count(q).find(q[i])] << " i = " << i << " j = " << Count(q).find(q[i]) << endl;
		//cout << mas[i][num_q(i,q)];

		cout << "\nChange data \n";
		write(mas, q.length() + 1, m);

		len = mas[len][num_q(i, q)];
		cout << "\nlen " << len << endl;
		//cout << "\nadd";
		//write(mas, q.length()+1, m);	
	}

	cout << "\nitog \n"; write(mas, q.length()+1, m);
}

int main()
{
	string s="AAAAAACACAGACCCFFACACAGA", q="ACACAGA";
	/*cout << "Enter the string: \n";
	getline(cin, s);
	cout << "Enter sample: \n";
	getline(cin, q);*/
	int num= Count(q).length()+1;

	int** mas = new int* [q.length()+1];
	for (int i = 0; i < q.length()+1; i++)
		mas[i] = new int[num];

	init_mas(mas, q, num);
	
	return 0;
}
