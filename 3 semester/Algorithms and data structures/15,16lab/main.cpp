#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

struct Tree
{
    int data;      

    Tree* left;
    Tree* right;
    Tree* parent;
};

bool IsOperator(char s)
{
    string znaki = ",()";

    if (znaki.find(s) != -1)
        return true;
    else
        return false;
}

Tree* MAKE(int data, Tree* p)
{
    Tree* q = new Tree;        
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

void Add(int data, Tree*& root)
{
    if (root == nullptr) {
        root = MAKE(data, nullptr);
        return;
    }
    Tree* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Tree* u = MAKE(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}

void CreateTree(string s, Tree*& root)
{
    string str = "";
    while (!s.empty())
    {
        if (IsOperator(s[0]))
        {
            s.erase(0,1);
            continue;
        }
        while (!IsOperator(s[0]))
        {
            str += s[0];
            s.erase(0, 1);
        }
        if (!str.empty())
        {
            Add(stoi(str), root);
            str = "";
        }
        s.erase(0, 1);
    }
}

void Pramo(Tree* root)
{
    if (root == nullptr)
        return;
    
    cout << root->data << " ";
    Pramo(root->left);
    Pramo(root->right);
}
void Center(Tree* root)
{
    if (root == nullptr)
        return;

    Center(root->left);
    cout << root->data << " ";
    Center(root->right);
}
void Obrat(Tree* root)
{
    if (root == nullptr)
        return;

    Obrat(root->left);
    Obrat(root->right);
    cout << root->data << " ";
}

void NeRecPr(Tree* root)
{
    cout << "\n NeRecPr  \n";
    stack<Tree*> st;
    st.push(nullptr);
    Tree* p = root;
    while (true)
    {
        if (p != nullptr)
        {
            st.push(p);
            cout << p->data << " ";
            p = p->left;
        }
        else
        {
            if (st.top() == nullptr) break;
            p = st.top(); st.pop();
            p = p->right;
        }
    } 
}

void CLEAR(Tree*& root)
{
    if (root == nullptr)
        return;

    CLEAR(root->left);
    CLEAR(root->right);

    delete root;
    root = nullptr;
}

int main()
{
    Tree* root = nullptr;
    string vhod;
    ifstream in("input.txt");
    getline(in, vhod);
 
    CreateTree(vhod, root);
    cout << "\n Pramo \n"; Pramo(root); cout << endl;
    cout << "\n Center \n"; Center(root); cout << endl;
    cout << "\n Obrat \n"; Obrat(root); cout << endl;
    NeRecPr(root); cout << endl;

    CLEAR(root);
	return 0;
}
