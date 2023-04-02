#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <stack>

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

		deg = new int[count];
		v = new list<int>[count];
	}
	void AddVers()
	{
		for (int i = 0; i < Num; i++)
			 deg[i]=0;
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
						deg[i]+=1;
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

	bool CheckForEuler()
	{
		int count = 0;
		for (int i = 0; i < Num; i++)
			if (deg[i] % 2 == 1)
				count++;

		if (count > 2)
			return false;
	}

	void EulerPath(int v)
	{
		ofstream out;out.open("out.txt");
		for (int i = 0; i < Num; i++)
			if (deg[i] % 2 == 1)
			{
				v = i;
				break;
			}
		stack<int>S;
		S.push(v);
		bool found_edge; int w = -1;
		while (!S.empty())
		{
			w = S.top();
			found_edge = false;
			for (int u = 0; u < Num; u++)
				if (FindE(w, u))
				{
					S.push(u);
					DelE(w, u);
					found_edge = true;
					break;
				}

			if (!found_edge)
			{
				S.pop();
				cout <<  w << " ";
				out <<  w << " ";
			}
		}
		out.close();
	}
protected:
	bool FindE(int w, int u)
	{
		for (int i = 0; i < g.size(); i++)
		{
			if (g[i].left == w && g[i].right == u)
				return true;
			if (g[i].right == w && g[i].left == u)
				return true;
		}
		
		return false;
	}
	void DelE(int w, int u)
	{
		for (int i = 0; i < g.size(); i++)
		{
			if (g[i].left == w && g[i].right == u)
				g.erase(g.cbegin() + i);
			if (g[i].right == w && g[i].left == u)
				g.erase(g.cbegin() + i);
		}
	}
private:
	int Num;
	list<int> *v;
	vector<Edge> g;
	int *deg;
};

int main()
{
	Graph G(n);
	G.AddVers();
	if (G.CheckForEuler())
		G.EulerPath(0);
	else
		cout << "Not Euler!";
	return 0;
}