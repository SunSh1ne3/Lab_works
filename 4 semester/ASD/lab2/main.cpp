#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <queue>
#include <fstream>
const int n = 8;
using namespace std;

class Graph
{
public:
	Graph(int count)
	{
		Num = count;
		color = new string[count];
		d = new int[count];
		v = new list<int>[count];
	}
	void AddVers()
	{
		int element;
		ifstream in; in.open("matrix.txt");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				in >> element;
				if (element == 1)
					v[i].push_back(j);
			}
		in.close();

		cout << "\n Dano: \n";
		for (int i = 0; i < n; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}
	void BFS(int s)
	{
		queue<int> Q;
		for (int u = 0; u < Num; u++)
		{
			color[u] = "white";
			d[u] = INT_MAX;
		}
		d[s] = 0;
		Q.push(s);
		int u = 0;
		while (!Q.empty())
		{
			u = Q.front(); Q.pop();
			for (auto i = v[u].begin(); i != v[u].end(); i++)
				if (color[*i] == "white")
				{
					color[*i] = "grey";
					d[*i] = d[u] + 1;
					Q.push(*i);
				}
			color[u] = "black";
		}
		ofstream out; out.open("D:/GitKraken/Lab_works/4 semester/ASD/lab2/out.txt");
		out << "Rast ot " << s << endl;
		for (int i = 0; i < Num; i++)
			out << i << ": " << d[i] << endl;

		out.close();
 	}

	
private:
	int Num;
	string* color;
	list<int>* v;
	int *d;
};

int main()
{
	Graph G(n);
	G.AddVers();
	G.BFS(0);
	return 0;
}
