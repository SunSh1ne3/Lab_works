#include <iostream>
#include <string>
#include <vector>

using namespace std;
int last(string q, char x)
{
	int count=0;
	for (int i = 0; i < q.size(); i++)
		if (q[i] == x)
			count =i;

	return q.size()-1 - count;
}

int penultimate(string q, char x)
{
	int count1=0, count2=0;
	bool f = true;
	for (int i = 0; i < q.size(); i++)
		if (q[i] == x)
		{
			if (f)
				count1 = i;
			else
				count2 = i;
			f = !f;
		}

	return count1 > count2 ? q.size() - 1 - count2: q.size() - 1 - count1;
}
int Num(string q, char x)
{
	int count = 0;
	for (int i = 0; i < q.size(); i++)
		if (q[i] == x)
			count ++;
	return count;
}

void init_d(int*& d, string q)
{
	for (int i = 0; i < 256; i++)
	{
		if (q[q.size() - 1] != char(i) && Num(q, char(i))!=0)
			d[i] = last(q, char(i));
		else if (q[q.size() - 1] == char(i) && Num(q, char(i)) >= 2)
			d[i] = penultimate(q, char(i));
		else if (q[q.size() - 1] == char(i) && Num(q, char(i)) == 1)
			d[i] = q.size() - 1;
		else
			d[i] = q.size();	
	}
	cout << "\nTable stop: \n";
	for (int i = 0; i < 256; i++)
		if(d[i]!=q.size())
			cout << char(i) << " " << d[i] << endl;	
}

void BM_pattern_search(string s, string q)
{
	if (s.size() < q.size())
		exit(1);
	vector<int> k_mas;
	int* d = new int[256];
	init_d(d, q);
	int j;
	cout << "\nStop number + stop symbol: \n";
	for (int k = 0; k <= s.size() - q.size(); k += d[s[k + q.size() - 1]])
	{
		cout << "k = " << k << " " << s[k + q.size() - 1] << " + " << d[s[k + q.size() - 1]] << endl;
		for (j = q.size() - 1; j > 0; j--)
			if (s[k + j] != q[j])
				break;
		if (j == 0)
			k_mas.push_back(k + 1);
	}
	if (k_mas.empty())
		cout << "Not found !! \n";
	else
		for (auto i : k_mas)
			cout << i << " ";
	delete[] d;
}

int main()
{
	string s="greater getter greating gettingetting", q = "getting";
	for (int i = 0; i < s.size(); i++)
		cout << s[i] << ":" << i+1 << " ";
	cout << endl;
	/*cout << "Enter the string: \n";
	getline(cin, s);
	cout << "Enter sample: \n";
	getline(cin, q);*/
	BM_pattern_search(s, q);
	return 0;
}