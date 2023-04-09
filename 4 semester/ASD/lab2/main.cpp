#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

class Graph
{
public:
	Graph()
	{
		int element;
		ifstream in; in.open("matrix.txt");
		if (!in)
			cout << "File! \n";
		else
			while (in >> element)
				Num++;
		in.close();

		Num = sqrt(Num);
		visit = new bool[Num];
		d = new int[Num];
		v = new list<int>[Num];
	}
	void AddVers()
	{
		int element;
		ifstream in; in.open("matrix.txt");
		if (!in)
			cout << "File! \n";
		else
		{
			for (int i = 0; i < Num; i++)
				for (int j = 0; j < Num; j++)
				{
					in >> element;
					if (element == 1)
						v[i].push_back(j);
				}
			in.close();
		}

		cout << "\n Dano: \n";
		for (int i = 0; i < Num; i++)
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
			visit[u] = false;
			d[u] = -1;
		}
		d[s] = 0;
		visit[s] = true;
		Q.push(s);
		int u = 0;
		while (!Q.empty())
		{
			u = Q.front(); Q.pop();
			for (auto i = v[u].begin(); i != v[u].end(); i++)
				if (!visit[*i])
				{
					visit[*i] = true;
					d[*i] = d[u] + 1;
					Q.push(*i);
				}
		}
		ofstream out; out.open("D:/GitKraken/Lab_works/4 semester/ASD/lab2/out.txt");
		out << "Rast ot " << s << endl;
		for (int i = 0; i < Num; i++)

			out << i << ": " << d[i] << endl;

		out.close();
 	}

	
private:
	int Num=0;
	bool* visit;
	list<int>* v;
	int *d;
};

int main()
{
	Graph G;
	G.AddVers();
	G.BFS(0);
	return 0;
}
