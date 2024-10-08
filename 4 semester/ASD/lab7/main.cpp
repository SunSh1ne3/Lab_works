#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>

const int INF=1e11;
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
	Graph()
	{
		int element;
		ifstream in; in.open("matrix.txt");
		if (!in)
		{
			cout << "File! \n";
			exit(1);
		}
		else
			while (in >> element)
				Num++;

		in.close();
		Num = sqrt(Num);
		parent = new int[Num];
		v = new list<int>[Num];
	}
	void AddVers()
	{
		int element;
		ifstream in; in.open("matrix.txt");
		if (!in)
		{
			cout << "File! \n";
			exit(1);
		}
		for (int i = 0; i < Num; i++)
			for (int j = 0; j < Num; j++)
			{
				in >> element;
				if (element != 0)
				{
					g.push_back(Edge(i, j, element));
					v[i].push_back(j);
				}
			}
		in.close();

		cout << "\n Dano: \n";
		for (int i = 0; i < Num; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(),ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	void MST()
	{
		for (int i = 0; i < Num; i++)
			inMST.push_back(false);

		for (int i = 0; i < Num; i++)
			if (!inMST[i])
				MST_Prim(i);

		ofstream out; out.open("D:/GitKraken/Lab_works/4 semester/ASD/lab7/out.txt");
		out <<"V - Parent : Weight \n";
		for (int i = 0; i < Num; i++)
		{
			if(parent[i]!=-1)
				out << i << " - " << parent[i]  << " : " << w(i, parent[i]) << endl;
			else
				out << i << " - root" << endl;
		}
	}
protected:

	void MST_Prim(int r)
	{
		//<data_top, prioritet>//
		vector<pair<int, int>> Q;

		for (int u = 0; u < Num; u++)
			Q.push_back(make_pair(u, INF));

		parent[Find(Q, r)] = -1;
		Q[Find(Q, r)].second = 0;

		while (!Q.empty())
		{
			pair<int, int> u = Extract_Min(Q);

			if (inMST[u.first])
				continue;
			inMST[u.first] = true;

			for (auto i = v[u.first].begin(); i != v[u.first].end(); i++)
			{
				if (inQueue(Q, *i) && w(u.first, *i) < Q[Find(Q, *i)].second)
				{
					parent[*i] = u.first;
					Q[Find(Q, *i)].second = w(u.first, *i);
				}
			}
		}
	}

	pair<int, int> Extract_Min(vector<pair<int, int>>& Q_m)
	{
		int minn = INF, x = 0; pair<int, int> u;
		for (int i = 0; i < Q_m.size(); i++)
		{
			if (Q_m[i].second < minn)
			{
				minn = Q_m[i].second;
				u = Q_m[i];
				x = i;
			}
		}
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

	//return index 'r' in Q//
	int Find(vector<pair<int, int>> Q_m, int r)
	{
		for (int i = 0; i < Q_m.size(); i++)
			if (Q_m[i].first == r)
				return i;

	}

	bool inQueue(vector<pair<int, int>> Q, int v)
	{
		for (int i = 0; i < Q.size(); i++)
			if (Q[i].first == v)
				return true;

		return false;
	}
private:
	int Num=0;
	list<int> *v;
	vector<Edge> g;
	vector <bool> inMST;
	int *parent;
};

int main()
{

	Graph G;
	G.AddVers();
	G.MST();
	return 0;
}