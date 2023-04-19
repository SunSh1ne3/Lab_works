#include <iostream>
#include <string>
#include <vector>

using namespace std;
void kmp_init(int* &prefix, string q)
{
	int len = 0;
	prefix[0] = 0;
	int i = 1;
	while (i < q.length())
	{
		if (q[i] == q[len])
		{
			len++;
			prefix[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
				len = prefix[len - 1];
			else
			{
				prefix[i] = 0;
				i++;
			}
		}
	}
}
void KMP_pattern_search(string s, string q)
{
	if (s.length() < q.length())
		exit(1);
	vector<int> k_mas;
	int* prefix = new int[q.length()];
	kmp_init(prefix, q);

	int j=0, i=0;

	while (i <= s.length())
	{
		if (q[j] == s[i])
		{
			i++;
			j++;
		}
		if (j == q.length())
		{
			k_mas.push_back(i-j+1);
			j = prefix[j - 1];
		}
		else if (i <= s.length() && q[j] != s[i])
		{
			if (j == 0)
				i++;		
			else
				j = prefix[j - 1];
		}
	}
	if (k_mas.empty())
		cout << "Not found!! \n";
	else
	{
		cout << "\nFound! \n";
		for (auto i : k_mas)
			cout << i << " ";
	}
	delete[] prefix;
}

int main()
{
	string s="aaaaabaaabaaabbabbababbbababbabbabbababbaaabbaaabaabaaabaaaa", q = "b";
	for (int i = 0; i < s.length(); i++)
		cout << s[i] << ":" << i+1 << " ";
	cout << endl;
	/*cout << "Enter the string: \n";
	getline(cin, s);
	cout << "Enter sample: \n";
	getline(cin, q);*/
	KMP_pattern_search(s, q);
	return 0;
}