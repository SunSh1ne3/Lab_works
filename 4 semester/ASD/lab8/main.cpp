#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>

const int n = 6, INF=1e11;
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
			{
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
		}
		in.close();
		
		cout << "\n Dano: \n";
		for (int i = 0; i < n; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(),ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	void Dijkstra(int a)
	{
		for (int v = 0; v < Num; v++)
		{
			d[v] = INF;
			Q.push_back(make_pair(v, false));
		}

		d[a] = 0;
		Q[a].second = true;

		while (!Q.empty())
		{
			pair<int, bool> u = Extract_Min(Q, d);
			for (auto i = v[u.first].begin(); i != v[u.first].end(); i++)
			{
				if (d[u.first] + w(u.first, *i) < d[*i])
				{
					Q[find(Q, *i)].second = true;
					d[*i] = d[u.first] + w(u.first, *i);
				}
			}
		}

		ofstream out; out.open("D:/GitKraken/Lab_works/4 semester/ASD/lab8/out.txt");
		out << "V : length \n";
		for (int i = 0; i < Num; i++)
			out << i << " : " << d[i] << endl;

	}
protected:

	pair<int, bool> Extract_Min(vector<pair<int, bool>>& Q_m, int d[n])
	{
		int minn = INF, x = -1; pair<int, bool> u;
		for (int i = 0; i < Q_m.size(); i++)
		{
			if (Q_m[i].second)
				if (d[Q_m[i].first] < minn)
				{
					minn = d[Q_m[i].first];
					u = Q_m[i];
					x = i;
				}
		}
		if (x != -1)
			Q_m.erase(Q_m.begin() + x);
		return u;
	}

	//return weight edge//
	int w(int u, int v)
	{
		for (int i = 0; i < g.size(); i++)
			if ((g[i].left == u && g[i].right == v) || (g[i].left == v && g[i].right == u))
				return g[i].weight;
	}

	int find(vector<pair<int, bool>> Q_m, int r)
	{
		for (int i = 0; i < Q_m.size(); i++)
			if (Q_m[i].first == r)
				return i;
	}

private:
	int Num;
	list<int> *v;
	vector<Edge> g;
	vector <pair<int, bool>> Q;
	int *d;
};

int main()
{
	Graph G(n);
	G.AddVers();
	G.Dijkstra(0);
	return 0;
}