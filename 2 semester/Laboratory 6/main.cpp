#include <iostream>
#include <cstdlib>

using namespace std;

struct T_List
{
	T_List* next;
	int data;
};

bool search(T_List* head, int age)
{
	
	T_List* tmp = head;
	
	while (tmp->data != age && tmp != nullptr)
		tmp = tmp->next;

	if (tmp->data == age)
	{		
		return true;
	}
	else
	{
		return false;
	}
	
	return false;
}

void ADD(T_List* head, int age)
{
	T_List* p = new T_List;
	p->data = age;

	p->next = head->next;
	head->next = p;
}
	
void Add_key(T_List* head, int key, int age)
{
	T_List* tmp = head;
	T_List* p = new T_List;
	if (search(head, key))
	{
		while (tmp->data != key && tmp!=nullptr)
		{
			tmp = tmp->next;
		}
		p->data = age;
		p->next =tmp->next;
		tmp->next = p;
	}
	else
	{
		cout << key << "not found " << endl;
	}

}

void Add_last(T_List* head, int age) 
{
		T_List* tmp = head;
		T_List* p = new T_List;
		p->data = age;

		while (tmp->next != nullptr) 
		{				
			tmp = tmp->next;
		}
		p->next = nullptr;
		tmp->next = p;
}

void DELETE(T_List* head, int key)
{
	T_List* tmp = head;
	T_List* p;
	while (tmp->next != nullptr)
	{
		if (tmp->next->data == key && tmp!= nullptr)
		{
			p = tmp->next;
			tmp->next = tmp->next->next;
			delete p;
		}
		else
			tmp = tmp->next;
	}
}

void Del_first(T_List*& head)
{
	T_List* tmp = head;
	head = head->next;
	delete tmp;
}

void Del_last(T_List* head)
{
	T_List* tmp = head;
	T_List* p = head;

	while (tmp->next!=NULL)
		tmp = tmp->next; 
	while (p->next != tmp)
		p = p->next;

	p->next = nullptr;
	delete tmp;
}

void CLEAR(T_List* head)
{
	T_List* p;
	T_List* tmp = head->next;
	while (tmp != nullptr)
	{
		p = tmp;
		tmp = tmp->next;
		delete p;
	}
}

void PRINT(T_List* head)
{
	T_List* tmp = head->next;
	while (tmp != nullptr)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int key, n = 0;
	T_List* head = new T_List;
	head->next = nullptr;
	ADD(head, 9);
	ADD(head, 6);
	ADD(head, 16);
	ADD(head, 4);
	ADD(head, 66);

	cout << "=== List ====" << endl;
	PRINT(head);

	cout << "What add in last position? " << n, << endl;
	cout << endl << "=== Add_last ( " << n << " ) ====" << endl;
	Add_last(head, n);
	PRINT(head);

	cout <<endl << "Enter element and key" << endl;
	cin >> n >> key;
	cout << endl << "=== Add_key ( " << n << " -> " <<  key << " ) ====" << endl;
	Add_key(head, n, key);
	PRINT(head);

	cout << "What delete? " << endl;
	cin >> n;
	cout << endl << "=== Delete ( " << n << " ) ====" << endl;
	DELETE( head, n);
	PRINT(head);

	cout << endl << "=== Del_first ====" << endl;
	Del_first(head);
	PRINT(head);

	cout << endl << "=== Del_last ====" << endl;
	Del_last(head);
	PRINT(head);

	CLEAR(head);
	delete head;
}
