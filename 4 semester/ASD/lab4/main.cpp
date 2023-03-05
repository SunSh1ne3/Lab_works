#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
const int n = 8, m = 8;
using namespace std;

class Graph
{
public:
	Graph(int count)
	{
		Num = count;
		color = new string[count];
		v = new list<int>[count];
	}
	void AddVers(int mas[n][m])
	{
		for (int i = 0; i <m; i++)
			for (int j = 0; j < n; j++)
				if (mas[i][j] == 1)
					v[i].push_back(j);
	}
	void Write_Vers()
	{
		cout << endl;
		for (int i = 0; i < m; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}

		cout << endl << "Comp: \n";
		for (int i = 0; i < Q.size(); i++)
		{
			if (!Q[i].empty()) {
				cout << i << ": ";
				copy(Q[i].begin(), Q[i].end(), ostream_iterator<int>(cout, " "));
				cout << endl;
			}
		}
	}

	void Find(int u, vector<int>* Q_m)
	{
		color[u] = "grey";
		
		for (auto i = v[u].begin(); i != v[u].end(); i++)
			if (color[*i] == "white")
				Find(*i, Q_m);
		Q_m->push_back(u);
		color[u] = "black";
	}

	void FindInGraph()
	{
		for (int u = 0; u < Num; u++)
			color[u] = "white";

		vector<int> time_queue;
		for (int u = 0; u < Num; u++)
		{
			if (color[u] == "white")
			{
				Find(u, &time_queue);
			}
			Q.push_back(time_queue);
			time_queue.clear();
		}

	}
private:
	int Num;
	string *color;
	list<int>* v;
	vector<vector<int>> Q;

};

int main()
{
	int A[n][n] = {
		{0,0,0,1,0,0,1,0},
		{0,0,0,0,1,1,0,1},
		{0,0,0,1,0,0,1,0},
		{1,0,1,0,0,0,1,0},
		{0,1,0,0,0,1,0,1},
		{0,0,0,0,1,0,0,1},
		{1,0,1,1,0,0,0,0},
		{0,1,0,0,1,1,0,0},
	};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
	
	Graph G(m);
	G.AddVers(A);
	G.FindInGraph();
	G.Write_Vers();

	return 0;
}
