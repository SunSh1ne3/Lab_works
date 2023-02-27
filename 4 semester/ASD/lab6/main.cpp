#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
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
	//cout << "m= "<< m << " <" << x[m].left << ", " << x[m].right << ", " << k << ">\n";
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
	void AddVers(int mas[n][n])
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mas[i][j] != 0)
				{
					g.push_back(Edge(i, j, mas[i][j]));
					v[i].push_back(j);
				}

		cout << "\n Dano: \n";
		for (int i = 0; i < n; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
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

		cout << "\n Itog: \n";
		cout << "<left, right, weight> \n";
		 for (int i = 0; i < A.size(); i++)
			 cout << "<" << A[i].left << ", " << A[i].right << ", " << A[i].weight << "> \n";
	}
private:
	int Num;
	list<int> *v;
	vector<Edge> g;
	int *parent;
};

int main()
{
	int A[n][n] = {
		{0,2,0,1,3,0,0,0,0},
		{2,0,0,0,3,0,0,5,0},
		{0,0,0,0,0,1,0,0,2},
		{1,0,0,0,0,0,3,0,0},
		{3,3,0,0,0,0,4,4,0},
		{0,0,1,0,0,0,0,0,2},
		{2,0,0,3,4,0,0,0,0},
		{0,5,0,0,4,0,0,0,0},
		{0,0,2,0,0,2,0,0,0}
	};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	Graph G(n);
	G.AddVers(A);
	G.MST_Kruskal();
	return 0;
}
