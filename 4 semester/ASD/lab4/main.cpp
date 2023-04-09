#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
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
	}
	void Write_Vers()
	{
		
		cout << endl;
		for (int i = 0; i < Num; i++)
		{
			cout << i << ": "; copy(v[i].begin(), v[i].end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
		ofstream out; out.open("D:/GitKraken/Lab_works/4 semester/ASD/lab4/out.txt");
		out << "Comp: \n";
		for (int i = 0; i < Q.size(); i++)
		{
			if (!Q[i].empty()) {
				out << i << ": ";
				copy(Q[i].begin(), Q[i].end(), ostream_iterator<int>(out, " "));
				out << endl;
			}
		}
	}

	void FindInGraph()
	{
		for (int u = 0; u < Num; u++)
			visit[u] = false;


		vector<int> time_queue;
		for (int u = 0; u < Num; u++)
		{
			if (!visit[u])
				Find(u, &time_queue);
			
			Q.push_back(time_queue);
			time_queue.clear();
		}
	}
protected:
	void Find(int u, vector<int>* Q_m)
	{
		visit[u] = true;

		for (auto i = v[u].begin(); i != v[u].end(); i++)
			if (!visit[*i])
				Find(*i, Q_m);
		Q_m->push_back(u);
	}
private:
	int Num=0;
	bool* visit;
	list<int>* v;
	vector<vector<int>> Q;
};

int main()
{	
	Graph G;
	G.AddVers();
	G.FindInGraph();
	G.Write_Vers();
	return 0;
}
