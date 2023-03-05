#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
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
		c = new int[count];
		v = new list<int>[count];
	}
	void AddVers(int mas[n][n])
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mas[i][j] == 1)
					v[i].push_back(j);

		cout << "\n Dano: \n";
		for (int i = 0; i < n; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	void BFS(int s, vector<int> *Q_m)
	{
		queue <int> Q;
		Q.push(s);
		int u = 0;
		while (!Q.empty())
		{
			u = Q.front(); 
			Q_m->push_back(Q.front()); 
			Q.pop();
			for (auto i = v[u].begin(); i != v[u].end(); i++)
				if (color[*i] == "white")
				{
					color[*i] = "grey";
					Q.push(*i);
				}
			color[u] = "black";
		}
		
 	}
	void BFS_GRAPH()
	{
		for (int u = 0; u < Num; u++)
			color[u] = "white"; 

		vector<int> time_queue;
		for (int u = 0; u < Num; u++)
		{
			if (color[u] == "white")
				BFS(u, &time_queue);
			Q.push_back(time_queue);
			time_queue.clear();
		}

		cout << endl << "Comp: \n";
		for (int i = 0; i < Q.size(); i++)
		{
			if (!Q[i].empty()) {
				cout << i + 1 << ": ";
				copy(Q[i].begin(), Q[i].end(), ostream_iterator<int>(cout, " "));
				cout << endl;
			}
		}
	}

	
private:
	int Num;
	string* color;
	list<int>* v;
	vector <int> comp;
	vector<vector<int>> Q;
	int *d, *c;
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
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	Graph G(n);
	G.AddVers(A);
	G.BFS_GRAPH();
	return 0;
}
