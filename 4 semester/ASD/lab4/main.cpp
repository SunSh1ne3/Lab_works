#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <vector>
#include <fstream>
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
	}
	void AddVers()
	{
		int element;
		ifstream in; in.open("matrix.txt");
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
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
		for (int i = 0; i < n; i++)
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
protected:
	void Find(int u, vector<int>* Q_m)
	{
		color[u] = "grey";

		for (auto i = v[u].begin(); i != v[u].end(); i++)
			if (color[*i] == "white")
				Find(*i, Q_m);
		Q_m->push_back(u);
		color[u] = "black";
	}
private:
	int Num;
	string *color;
	list<int>* v;
	vector<vector<int>> Q;
};

int main()
{	
	Graph G(n);
	G.AddVers();
	G.FindInGraph();
	G.Write_Vers();
	return 0;
}
