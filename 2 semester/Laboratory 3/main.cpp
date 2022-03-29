#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cmath>
const int N = 100000;
const int M = 10000;

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

int Binarn_Search(int low, int high, int* x, int k)
{
	if (k < x[low])
	{
		return -1;
	}
	if (k == x[low])
	{
		return 0;
	}
	if (k > x[high])
	{
		return -1;
	}
	int left = 0;
	int right = N - 1;
	while ((left + 1) < right) 
	{
		int c = floor((left + right) / 2);
		if (k > x[c])
		{
			left = c;
		}
		else
		{
			right = c;
		}
	}
	if (x[right] == k)
	{
		return right;
	}
	else
	{
		return -1;
	}
}

double f(double x)
{
	return log(x) - 1;
}

double Bisection(double a, double b)
{
	double eps = 1e-4;
	while (1)
	{
		double x = (a + b) / 2;
		if ((abs(x - a) < eps) && (abs(x - b) < eps))
		{
			return x;
		}
		else if (f(x) * f(a) > 0)
		{
			a = x;
		}
		else
		{
			b = x;
		}
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int x[N];
	int k = 0;
	double a, b = 0;
	for (int i = 0; i < N; i++)
	{
		x[i] = rand()%50;
	}
	Quick_Sort(0, N-1, x);

	cout << "Введите, что ищем: " << endl;
	cin >> k;

	Timer t;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (x[j] == k)
			{
				break;
			}
		}
	}
	cout << "Время выполнения с помощью прохода по циклам: " << t.elapsed() << endl;

	t.reset();
	
	for (int i = 0; i < M; i++)
	{
		int j = Binarn_Search(0, N - 1, x, k);
	}
	cout << "Время выполнения с помощью прохода с помощью Бинарного : " << t.elapsed() << endl;
	
	cout << "Введите левую и правую границы для поиска значения ln(x) - 1 = 0 : " << endl;
	cin >> a >> b;

	cout << Bisection(a, b);

	return 0;
}