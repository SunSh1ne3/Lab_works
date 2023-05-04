#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

float weight(vector<float> basket)
{
	float count=0;
	for (int i = 0; i < basket.size(); i++)
		count += basket[i];	
	return count;
}

int main()
{
	srand(time(0));
	cout << "How many things? ";
	int count;	cin >> count;

	vector <float> things;
	float a;
	while (things.size() < count)
	{
		cin >> a;
		things.push_back(a);
	}
	for (int i = 0; i < things.size(); i++)
		cout << things[i] << " ";

	vector<vector<float>> baskets;

	while (!things.empty())
	{
		for (int i = 0; i < things.size(); i++)
		{
			vector<float> basket;
			while (weight(basket) <= 1)
			{
				if (weight(basket) + things[i] <= 1)
				{
					basket.push_back(things[i]);
					things.erase(things.begin() + i);
					i--;
				}
				i++;
				if (i >= things.size())
					break;

			}
			baskets.push_back(basket);
			basket.clear();
		}
	}
	cout << "\n \nNeed " << baskets.size() << " baskets \n";
	for (int i = 0; i < baskets.size(); i++)
	{
		cout << i+1 << ":";
		for (auto j : baskets[i])
			cout << j << " ";
		cout << endl;
	}
	return 0;
}