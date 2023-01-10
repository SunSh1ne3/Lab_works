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
void print_Tree(Tree* root, int level)
{
    if (root == nullptr)
        return;
 
    print_Tree(root->right, level + 1);
    for (int i = 0; i < level; i++)
        cout << "   ";
    cout << root->data << endl;
    print_Tree(root->left, level + 1);
}

Tree* Search(int data, Tree* root) 
{
    if (root == nullptr)
        return root;
    if (root->data == data)
        return root;
    if (data < root->data)
        return Search(data, root->left);
    else
        return Search(data, root->right);
}

Tree* min(Tree* x)
{
    if (x->left == nullptr)
        return x;
    else
        return min(x->left);
}
Tree* Del(int x, Tree* root)
{
    if (root == nullptr)
        return root;
    if (x < root->data)
        root->left = Del(x, root->left);
    else if (x > root->data)
        root->right = Del(x, root->right);
    else if (root->left != nullptr && root->right != nullptr) {
        root->data = min(root->right)->data;
        root->right = Del(root->data, root->right);
    }
    else
        if (root->left != nullptr)
            root = root->left;
        else if (root->right != nullptr)
            root = root->right;
        else
            root = nullptr;
    return root;
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

    ifstream in("input.txt");
    string vhod; getline(in, vhod);
    int x,k;
    CreateTree(vhod, root);
    start:
    print_Tree(root,0);

    cout << "\n   Menu: \n 1. Add \n 2. Delete \n 3. Find \n Select action number ";
    cin >> x;
    switch (x)
    {
        case(1):
            cout << "\n Enter number to add "; cin >> k; Add(k, root); break;
        case(2):
            cout << "\n Enter number to delete "; cin >> k; 
            if (Search(k, root) == nullptr)
                cout << "\n Sorry, but this number is not in the tree...\n";
            else
                Del(k, root);
                break;
        case(3):
            cout << "\n nter number to find "; cin >> k; 
            if (Search(k, root) == nullptr)
                cout << "\n Sorry, but this number is not in the tree...\n";
            else
                cout << "\n There is such a number \n \n";
            break;
        case(404):
            return -1;
        default: std::cout << "Choose another... "; goto start; break;
    }

    goto start;
    CLEAR(root);
	return 0;
}
