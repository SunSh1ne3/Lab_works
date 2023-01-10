
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <iomanip>

int N = 10000;
int M = 1000;

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

struct Elem
{
    int data;      

    Elem* left;
    Elem* right;
    Elem* parent;
};

Elem* MAKE(int data, Elem* p)
{
    Elem* q = new Elem;        
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

void ADD(int data, Elem*& root)
{
    if (root == nullptr) {
        root = MAKE(data, nullptr);
        return;
    }
    Elem* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Elem* u = MAKE(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}
 
void PASS(Elem* v) //output
{
    if (v == nullptr)
        return;
    
    PASS(v->left);
cout << v->data << " ";
    PASS(v->right);
  
}

void print_Tree(Elem* v, int level)
{
    if (v == nullptr)
    {
        return;
    }   
        print_Tree(v->right, level + 1);
        for (int i = 0; i < level; i++) 
            cout << "   ";
        cout << v->data  << endl;
        print_Tree(v->left, level + 1);
}

Elem* SEARCH(int data, Elem* v) // easy search   
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}

Elem* Search(int data, Elem* v,int number) // search with number
{
    ofstream out("output.txt");
    if (v == nullptr)
    {
        out << data << " - n " << endl;
        cout << data << " - n " << endl;
        return v;
    }
        
    else if (v->data == data)
    {
        cout << v-> data << " in depth -  " << number << endl;;
        out << v->data << " in depth - " << number << endl;;
        return v;
    }
        
    else if (data < v->data)
        return Search(data, v->left, number+1);
    else
        return Search(data, v->right, number+1);
}

void DELETE(int data, Elem*& root)
{  
    Elem* u = SEARCH(data, root);
    if (u == nullptr)
        return;

    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        delete root;
        root = nullptr;
        return;
    }

    if (u->left == nullptr && u->right != nullptr && u == root) 
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right == nullptr && u == root) 
    {
        Elem* t = u->left;
        while (t->right != nullptr)
            t = t->right;
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right != nullptr && u==root)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
    delete u;
}
 
void CLEAR(Elem*& v)
{
    if (v == nullptr)
        return;

    CLEAR(v->left);
    CLEAR(v->right);

    delete v;
    v = nullptr;
}


int main()
{
    Elem* root = nullptr;
    ifstream in("input.txt");
    char a;
    int b;

    while (!in.eof())
    {
        in >> a;
        in >> b;
        if (a == '+')
        {
            ADD(b, root);
            cout << "+ " << b << endl;
            cout << " Tree: " << endl;
            PASS(root);
            //print_Tree(root, 1);
            cout << endl;
        }
        else if (a == '?')
        {
            Search(b, root, 1);
        }
        else if (a == '-')
        {
            DELETE(b, root);
            cout << "- " << b << endl;
            cout << " Tree: " << endl;
            PASS(root);
            //print_Tree(root, 1);
            cout << endl;
        }
        else if (a == 'E')
        {
            break;
        }
    }
    cout << "======" << endl;
    PASS(root);
   // print_Tree(root, 0);
    CLEAR(root);
	return 0;
}