#include <iostream>
#include <string>

using namespace std;
int Hash(string s, int M)
{
	int h = 0;
	for (int i = 0; i < M; i++)
		h += s[i];
	return h;
}
int hash_update(int hs, char out, char in)
{
	return hs + in - out;
}
void RK_pattern_search(string s, string q)
{
	if (q.size() > s.size())
		exit(1);
	int hs = Hash(s, q.size());
	int hq = Hash(q, q.size());

	for (int k = 0; k <= s.size() - q.size(); k++)
	{
		int j = 0;
		if (hs == hq)
		{
			for (j = 0; j < q.size(); j++)
				if (s[k + j] != q[j])
					break;
			if(j==q.size())
				cout << " =k= " << k+1 << endl;						
		}
		hs = hash_update(hs, s[k], s[k+q.size()]);
	}
}

int main()
{
	string s, q;
	cout << "Enter the string: \n";
	getline(cin, s);
	cout << "Enter sample: \n";
	getline(cin, q);

	RK_pattern_search(s, q);
	return 0;
}