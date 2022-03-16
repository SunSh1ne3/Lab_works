#include <iostream>
#include <cstdlib>
#include <chrono>
const int N = 10000;
const int M = 1000;

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

void SEARCH(T_List* head, int key)
{
	T_List* p = head;
	while (p != nullptr)
	{
		p = p->next;
		if (p->data == key)
		{
			//cout <<"Yeah! " << p->data << endl;
			break;
		}
	}
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


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	T_List* head = new T_List;
	head->next = nullptr;
	int mas[N];
	int key;

	cout << "Что ищем? (числа от 1 до 10)" << endl;
	cin >> key;
	if ((key < 1) || (key > 10))
	{
		cout << "Читай внимательнее!" << endl;
		return 1;
	}

	//заводим данные в спсиок
	for (int i = 0; i < N; i++)
	{
		ADD(head, rand() % 10 + 1);
	}
	
	Timer a;
	//поиск в списке
	for (int i = 0; i < M; i++)
	{
		SEARCH(head, key);
	}
	cout << " Time T_List: " << a.elapsed() << endl;

	//заводим данныфе в массив
	for (int i = 0; i < N; i++)
	{
		mas[i]= rand() % 10 + 1;
	}

	a.reset();
	//поиск в массиве
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mas[j] == key)
			{
				//cout << "Yeah! " << endl;
				break;
			}
		}
	}
	cout << " Time mas: " << a.elapsed() << endl;
	
	CLEAR(head);
	delete head;
	return 0;
}