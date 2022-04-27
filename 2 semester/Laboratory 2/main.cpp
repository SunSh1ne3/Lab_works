#include <iostream>
#include <cstdlib>
#include <chrono>

const int N = 10;
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

void Bubble_Sort(int* x, int n)
{
	for (int i = 1; i < n ; i++)
	{
		if (x[i] > x[i - 1])
		{
			continue;
		}
		int j = i - 1;
		while ((j >= 0) && (x[j] > x[j + 1]))
		{
			swap(x[j], x[j + 1]);
			j--;
		}
	}
}

void BubbleSort(int* x, int n)
{
	bool f = 0;
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (x[i] > x[i + 1])
			{
				swap(x[i], x[i + 1]);
				f = 1;
			}
		}
		if (f == 0)
		{
			break;
		}
	}
}

void Quick_Sort(int low, int high, int* x)
{
	if (low >= high)
	{
		return;
	}
	int m = (low + high) / 2 + 1;
	int k = x[m];
	int l = low - 1;
	int r = high + 1;
	while (1)
	{
		do
		{
			l++;
		} while (x[l] < k);
		do
		{
			r--;
		} while (x[r] > k);
		if (l >= r)
		{
			break;
		}
		swap(x[l], x[r]);
	}
		r = l;
		l--;
		Quick_Sort(low, l, x);
		Quick_Sort(r, high, x);
}

int main()
{
	srand(time(NULL));
	int x[N];
	int q[N];
	for (int i = 0; i < N; i++)
	{
		x[i] = rand()% 100 + 1;
		q[i] = rand() % 100 + 1;
	}

	Timer t;
	Bubble_Sort(x, N);
	cout << "Lead time Bubble_Sort: " << t.elapsed() << endl;

	t.reset();
	Quick_Sort(0, N-1, q);
	cout << "Lead time Quick_Sort: " << t.elapsed() << endl;

	return 0;
}