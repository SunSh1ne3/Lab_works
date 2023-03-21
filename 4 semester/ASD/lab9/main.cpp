#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>

const int n = 5, INF=1e11;
using namespace std;
struct Edge {
	int left, right, weight;
	Edge(int m_left, int m_right, int m_weight)
	{
		left = m_left;
		right = m_right;
		weight = m_weight;
	}
};

class Graph
{
public:
	Graph(int count)
	{
		Num = count;
		d = new int[count];
		v = new list<int>[count];
	}
	void AddVers()
	{
		int element;
		ifstream in; in.open("matrix.txt");
		if (!in)
			cout << "File! \n"; 
		else
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
				{
					in >> element;
					if (element != 0)
					{
						g.push_back(Edge(i, j, element));
						v[i].push_back(j);
					}
				}
		}
		in.close();
		
		cout << "\n Dano: \n";
		for (int i = 0; i < n; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(),ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}
	void BellmanFord(int src)
	{
		for (int i = 0; i < Num; i++)
			d[i] = INF;
		d[src] = 0;

		for (int i = 0; i < Num-1; i++)
			for (int j = 0; j < g.size(); j++)
				if (d[g[j].left]!=INF && d[g[j].left] + g[j].weight < d[g[j].right])
					d[g[j].right] = d[g[j].left] + g[j].weight;

		ofstream out; out.open("E:/GitKraken/Lab_works/4 semester/ASD/lab9/out.txt");
		out << "V : length \n";
		for (int i = 0; i < Num; i++)
			out << i << " : " << d[i] << endl;
	}
	
private:
	int Num;
	list<int> *v;
	vector<Edge> g;
	int *d;
};

int main()
{
	Graph G(n);
	G.AddVers();
	G.BellmanFord(0);
	return 0;
}