#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <fstream>
const int n = 9;
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
void Quick_Sort(int low, int high, vector<Edge> &x)
{
	if (low >= high)
	{
		return;
	}
	int m = (low + high) / 2 + 1;
	int k = x[m].weight;
	int l = low - 1;
	int r = high + 1;
	while (1)
	{
		do
		{
			l++;
		} while (x[l].weight < k);
		do
		{
			r--;
		} while (x[r].weight > k);
		if (l >= r)
		{
			break;
		}
		swap(x[l], x[r]);
	}
	r = l;
	l--;
	Quick_Sort(low, l, x);
	Quick_Sort(r, high, x);
}

class Graph
{
public:
	Graph(int count)
	{
		Num = count;
		parent = new int[count];
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
				if (element != 0)
				{
					g.push_back(Edge(i, j, element));
					v[i].push_back(j);
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
	
	int Find_Set(int i)
	{
		if (parent[i] == i)
			return i;
		else
			return Find_Set(parent[i]);
	}
	void Union(int u, int v)
	{
		parent[u] = parent[v];
	}
	void MST_Kruskal()
	{
		vector<Edge> A;
		for (int i = 0; i < Num; i++)
			parent[i] = i;

		Quick_Sort(0, g.size() - 1, g);

		for (int i = 0; i < g.size(); i++)
			if (Find_Set(g[i].left) != Find_Set(g[i].right))
			{
				A.push_back(g[i]);
				Union(Find_Set(g[i].left), Find_Set(g[i].right));
			}
		ofstream out; out.open("D:/GitKraken/Lab_works/4 semester/ASD/lab6/out.txt");
		out << "Itog: \n";
		out << "Edges : Weight \n";
		 for (int i = 0; i < A.size(); i++)
			 out << i+1 << ". " <<  A[i].left << " - " << A[i].right << " : " << A[i].weight << "\n";
	}
private:
	int Num;
	list<int> *v;
	vector<Edge> g;
	int *parent;
};

int main()
{
	Graph G(n);
	G.AddVers();
	G.MST_Kruskal();
	return 0;
}