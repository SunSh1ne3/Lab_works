#include <iostream>
#include <string>
#include <list>
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
			cout << "File! \n";
		else
			while(in >> element)
				Num++;
		in.close();
		Num = sqrt(Num);
		deg = new pair<int, int>[Num];
		v = new list<int>[Num];
		B = new vector<int>[Num];
	}
	void AddVers()
	{
		int element; 
		ifstream in; in.open("matrix.txt");
		if (!in)
			cout << "File! \n"; 
		else
		{
			for (int i = 0; i < Num; i++)
				for (int j = 0; j < Num; j++)
				{
					in >> element;
					if (element != 0)
					{
						v[i].push_back(j);
						deg[i].second++;
						deg[i].first = i;
					}
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

	void Sort()
	{
		for (int i = 0; i < Num - 1; i++)
			for (int j = i + 1; j < Num; j++)
				if (deg[i].second < deg[j].second)
					swap(deg[i], deg[j]);
	}
	void Paint()
	{
		int k = 0;
		B[k].push_back(deg[0].first);
	Start:
		for (int i = 1; i < Num; i++)
		{
			if (!Color_B(deg[i].first) && !Smegni(deg[i].first, B[k]))
				B[k].push_back(deg[i].first);
			else continue;
		}
		for (int i = 0; i < Num; i++) {
			if (!Color_B(i)) {
				k++;
				goto Start;
			}
			else
				continue;
		}

		cout << endl;
		for (int i = 0; i < Num; i++)
		{
			if (!B[i].empty())
			{
				cout << char(i+65) << ": ";
				for (int j = 0; j < B[i].size(); j++)
					cout << B[i][j] << " ";
				cout << endl;
			}
		}
	}

protected:
	bool Smegni(int j, vector<int>B_m)
	{
		for(auto u:B_m)
			for (auto i = v[u].begin(); i != v[u].end(); i++)
				if (j == *i)
					return true;
		return false;
	}
	bool Color_B(int u)
	{
		for (int i = 0; i < Num; i++)
			for (int j = 0; j < B[i].size(); j++)
			{
				if (B[i][j] == u)
					return true;
				else
					continue;
			}
		return false;
	}
private:
	int Num=0;
	list<int> *v;
	vector<int> *B;
	pair<int,int>* deg;
	
};

int main()
{
	Graph G;
	G.AddVers();
	G.Sort();
	G.Paint();
	return 0;
}


