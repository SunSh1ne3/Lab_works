#include <iostream>
#include <vector>
using namespace std;

bool SumSub(vector<int> num, int n, int sum)
{
	if (sum == 0)
		return true;

	if (n == 0)
		return false;

	if (num[n - 1] > sum)
		return SumSub(num, n - 1, sum);

	return SumSub(num, n - 1, sum) || SumSub(num, n - 1, sum - num[n - 1]);
}

int main()
{
	srand(time(0));
	cout << "Sum? \n";
	int sum; cin >> sum;
	cout << "How many numbers?\n";
	int count; cin >> count;
	vector<int> numbers;
	for (int i = 0; i < count; i++)
	{
		numbers.push_back(rand() % sum + 1);
		cout << numbers[i] << " ";
	}
	if (SumSub(numbers, numbers.size(), sum))
		cout << "\n Sum is found! \n";
	else
		cout << "\n Oh no :( \n";

	return 0;
}