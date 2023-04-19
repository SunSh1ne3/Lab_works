#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

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
	
}


void init_mas(int** mas, string q, int m)
{	
	int len = 0;	

	for (int j = 0; j < m; j++)
		mas[0][j] = 0;
	mas[0][0] = 1;

	for (int i = 1; i < q.length() + 1; i++)
	{	
		for (int j = 0; j < m; j++)
			mas[i][j] = mas[len][j];

		mas[i][Count(q).find(q[i])] = i + 1;

		len = mas[len][Count(q).find(q[i])];
	}

	cout << "\nTable: \n";
	for (int i = 0; i < q.length() + 1; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void SM_pattern_search(string s, string q, int **mas)
{
	if (s.length() < q.length())
		exit(1);
	vector<int> k_mas;
	int state = 0;
	for (int i = 0; i < s.length() ; i++)
	{
		if (Count(q).find(s[i]) == string::npos)
			state = mas[state][Count(q).length()];
		else
			state = mas[state][Count(q).find(s[i])];
		if (state == q.length())
			k_mas.push_back(i - q.length() + 2);
	}
	if (k_mas.empty())
		cout << "\nNot found!! \n";
	else
	{
		cout << "\nFound! \n";
		for (auto i : k_mas)
			cout << i << " ";
	}
}

int main()
{
	string s="AAAAAACACAGACCCFFACACAGA", q="ACACAGA";
	/*cout << "Enter the string: \n";
	getline(cin, s);
	cout << "Enter sample: \n";
	getline(cin, q);*/
	for (int i = 0; i < s.length(); i++)
		cout << i+1 << ":" << s[i] << "  ";
	cout << endl;

	int alphabet= Count(q).length()+1;
	int** mas = new int* [q.length()+1];
	for (int i = 0; i < q.length()+1; i++)
		mas[i] = new int[alphabet];

	init_mas(mas, q, alphabet);
	SM_pattern_search(s, q,mas);

	for (int i = 0; i < q.length(); i++)
		delete[] mas[i];
	delete[] mas;
	return 0;
}
