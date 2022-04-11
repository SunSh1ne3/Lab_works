#include <iostream>
#include <cstdlib>
#include <chrono>
int M = 4;

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

struct T_List
{
	T_List* next;
	int data;
};

void ADD(T_List* head, int age)
{
	T_List* p = new T_List;
	p->data = age;

	p->next = head->next;
	head->next = p;
}

bool SEARCH(T_List* head, int key)
{
	T_List* p = head;
	while (p != nullptr)
	{
		p = p->next;
		if (p->data == key)
		{
			cout << p->data << " Yeah! " << endl;
			return true;
		}
		else
		{
			cout << p->data << " No " << endl;
			return false;
		}
	}
	return false;
}

void CLEAR(T_List* head)
{
	T_List* tmp;
	T_List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}

void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int key = 0;
	cout << "Введите количество элементов" << endl;
	int n; cin >> n;
	T_List* head = new T_List;
	head->next = nullptr;
	int* mas = new int[n];
	int* k = new int[M];

	//заводим данные в спсиок
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 10 + 1;
		ADD(head, mas[i]);
	}

	PRINT(head);
	cout << endl;

	for (int i = 0; i < M; i++)
	{
		k[i] = rand() % 10;
	}
	Timer a;

	//поиск в списке
	for (int i = 0; i < M; i++)
	{
		if (SEARCH(head, k[i]))
		{
			cout << k[i] << " - Yes!" << endl;
		}
		else
		{
			cout <<k[i] << " - No" << endl;
		}
	}
	
	
	cout << " Time T_List: " << a.elapsed() << endl;

	cout << "Вывод массива: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;

	int L = 0;
	a.reset();
	//поиск в массиве
	for (int i = 0; i < M; i++)
	{
		key = rand() % 10;
		for (int j = 0; j < n; j++)
		{
			if (mas[j] == key)
			{
				L = 1;
			}
		}
		if (L == 1)
		{
			cout <<key<< " Yeah! " << endl;
			L = 0;
		}
		else
		{
			cout << key << " NO" << endl;
		}
	}
	
	cout << " Time mas: " << a.elapsed() << endl;
	
	CLEAR(head);
	delete head;
	delete [] mas;
	return 0;
}