#include <iostream>
#include <string>
#include <list>
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
		{
			cout << "File! \n";
			exit(1);
		}
		else
			while (in >> element)
				Num++;
		in.close();
		Num = sqrt(Num);
		visit = new bool[Num];
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
				if (element == 1)
					v[i].push_back(j);
			}
		in.close();

		cout << "\n Dano: \n";
		for (int i = 0; i < Num; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	void BFS_GRAPH()
	{
		for (int u = 0; u < Num; u++)
			visit[u] = false; 

		vector<int> time_queue;
		for (int u = 0; u < Num; u++)
		{
			if (!visit[u])
				BFS(u, &time_queue);
			Q.push_back(time_queue);
			time_queue.clear();
		}

		ofstream out; out.open("D:/GitKraken/Lab_works/4 semester/ASD/lab3/out.txt");
		out << endl << "Comp: \n";
		for (int i = 0; i < Q.size(); i++)
		{
			if (!Q[i].empty()) {
				out << i + 1 << ": ";
				copy(Q[i].begin(), Q[i].end(), ostream_iterator<int>(out, " "));
				out << endl;
			}
		}
	}
protected:
	void BFS(int s, vector<int>* Q_m)
	{
		queue <int> Q;
		Q.push(s);
		int u = 0;
		while (!Q.empty())
		{
			u = Q.front();
			visit[u] = true;
			Q_m->push_back(Q.front());
			Q.pop();
			for (auto i = v[u].begin(); i != v[u].end(); i++)
				if (!visit[*i])
				{
					visit[*i] = true;
					Q.push(*i);
				}
		}
	}
private:
	int Num=0;
	bool* visit;
	list<int>* v;
	vector <int> comp;
	vector<vector<int>> Q;
};

int main()
{
	Graph G;
	G.AddVers();
	G.BFS_GRAPH();
	return 0;
}
