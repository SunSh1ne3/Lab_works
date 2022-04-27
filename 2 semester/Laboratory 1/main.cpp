#include <iostream>
#include <chrono>

using namespace std;
class Timer
{
private:
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, std::ratio<1> >;

	chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

bool Glas(char c[10000], char glas[7])
{
	for (int i = 0; i < strlen(c); i++)
	{
		for (int j = 0; j < strlen(glas); j++)
		{
			if (c[i] == glas[j])
			{
				return true;
			}
		}
	}
	return false;
}

void Sort(char c[10000])
{
	for (int i = 0; i < strlen(c) - 1; i++)
	{
		for (int j = i + 1; j < strlen(c); j++)
		{
			if (c[i] > c[j])
			{
				swap(c[i], c[j]);
			}
		}
	}
}

int main()
{
	char c[10000];
	cout << "Enter the string" << endl;
	cin.getline(c, 10000);
	char glas[7] = "eyuioa";
	Timer t;
	if (Glas(c, glas))
	{
		Sort(c);
		cout << "Lead time: " << t.elapsed() << endl;
		cout << "Yes!" << endl;
	}
	else
	{
		cout << "Lead time: " << t.elapsed() << endl;
		cout << "No" << endl;
	}

	for (int i = 0; i < strlen(c); i++)
	{
		cout << c[i];
	}

	return 0;
}