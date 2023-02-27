﻿#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
const int n = 8;
using namespace std;

class Graph
{
public:
	Graph(int count)
	{
		Num = count;
		color = new string[count];
		v = new list<int>[count];
		v1 = new list<int>[count];
		for (int i = 0; i < Num; i++)
			t.push_back(0);
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
			cout << i+1 << ": "; copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	int maxy(vector<int> mas)
	{
		int maxs = -1;
		for (int i = 0; i < mas.size(); i++)
			if (mas[i] > maxs)
				maxs = mas[i];
		return maxs;
	}

	void invers(int A[n][n])
	{
		int ** mas = new int*[n];
		for (int i = 0; i < n; i++)
			mas[i] = new int[n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mas[i][j] = A[j][i];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mas[i][j] == 1)
					v1[i].push_back(j);

		cout << " Inv v: \n";
		for (int i = 0; i < n; i++)
		{
			cout << i << ": "; copy(v1[i].begin(), v1[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}

		for (int i = 0; i < n; i++)
			delete[] mas[i];
		delete[] mas;
	}

	void DFS()
	{
		for (int u = 0; u < Num; u++)
			color[u] = "white";

		for (int u = 0; u < Num; u++)
			if (color[u] == "white")
				Find(u);

		cout << "\n DFS: \n";
		for (int i = 0; i < Num; i++)
			cout << i << ": " << t.at(i) << endl;
		cout << endl;
	}

	void Find(int u)
	{
		color[u] = "grey";
		t[u] = ++time;
		
		for (auto i = v[u].begin(); i != v[u].end(); i++)
			if (color[*i] == "white")
				Find(*i);

		color[u] = "black";
		t[u] = time++;
	}

	void DFS1()
	{
		for (int u = 0; u < Num; u++)
			color[u] = "white";

		int maxx=-1;
		vector<int> time_queue;
		for (int i = 0; i < Num; i++)
			for (int u = 0; u < Num; u++)
			{
				maxx = maxy(t);
				if (color[u] == "white" && t.at(u) == maxx)
					Find1(u, &time_queue);

				Q.push_back(time_queue);
				time_queue.clear();
			}

		cout << endl << " Comp: \n";
		for (int i = 0; i < Q.size(); i++)
		{
			if (!Q[i].empty()) {
				cout << i + 1 << ": ";
				copy(Q[i].begin(), Q[i].end(), ostream_iterator<int>(cout, " "));
				cout << endl;
			}
		}
	}
	void Find1(int u, vector<int>* Q_m)
	{
		color[u] = "grey";

		for (auto i = v1[u].begin(); i != v1[u].end(); i++)
			if (color[*i] == "white")
				Find1(*i, Q_m);
		Q_m->push_back(u + 1);
		color[u] = "black";

		t[u] = 0;
	}
private:
	int Num;
	string* color;
	list<int>* v;
	list<int>* v1;
	vector<int> t;
	vector<vector<int>> Q;

	int time = 0;
};

int main()
{
	int A[n][n] = {
		{0,1,0,0,0,0,0,0},
		{0,0,1,0,1,1,0,0},
		{0,0,0,1,0,0,1,0},
		{0,0,1,0,0,0,0,1},
		{1,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,1,0},
		{0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,1,0},
	};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	Graph G(n);
	G.AddVers(A);
	G.DFS();
	G.invers(A);
	G.DFS1();

	return 0;
}
