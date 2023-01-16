#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class T_List
{
public:
    T_List() 
    {
        data = "\0";
        next = nullptr;
    }
    T_List(string str)
    {
        data = str;
        next = nullptr;
    }
    void AddToList(T_List*& head, string str)
    {
        T_List* p = new T_List;
        p->data = str;
        p->next = head;
        head = p;
    }
    bool FindToList(T_List* head, string str)
    {
        T_List* p = head;
        while (p->next != nullptr)
        {
            p = p->next;
            if (p->data == str)
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
    T_List* Find(T_List* head, string str)
    {
        T_List* p = head;
        while (p->next != nullptr)
        {
            p = p->next;
            if (p->data == str)
                return p;
        }
    }

    void DelToList(T_List*& head, string str)
    {
        T_List* tmp;
        T_List* p = head;
        while (p != nullptr)
        {
            if (p->next == Find(head, str))
            {
                tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            }
            else
                p = p->next;
        }
    }

    void write(T_List* head)
    {
        T_List* p = head;
        while (p!=NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void ClearList(T_List* head)
    {
        T_List* tmp;
        T_List* p = head;
        while (p->next != nullptr)
        {
            tmp = p;
            p = p->next;
            delete tmp;
        }
    }
   
private:
    T_List* next;
    string data;
};

class HashTable
{
public:
    HashTable()
    {
        T_List* p = new T_List;
        
        for (int i = 0; i < size_table; i++)
            table[i] = p;
        delete p;
    }

    ~HashTable()
    {
        for (int i = 0; i < size_table; i++)
            table[i]->ClearList(table[i]);
    }

    int HashFunction(string str)
    {
        int Sum = 0;
        for (int i = 0; i < str.length(); i++)
            Sum += int(str[i]);

        return Sum % size_table;
    }

    void AddToTable(string str)
    {   
        table[HashFunction(str)]->AddToList(table[HashFunction(str)], str);
    }
    void AddInTable()
    {
        ifstream in; in.open("table.txt");

        char vhod = ' '; string str = "";
        while (!in.eof())
        {
            in.get(vhod);
            if ((vhod == ' ' || vhod == '\n') && !str.empty())
            {
                AddToTable(str);
                str = "";
            }
            else
                str += vhod;
        }
        if (!str.empty())
            AddToTable(str);
        in.close();
    }

    bool FindToTabel(string str)
    {
        if(table[HashFunction(str)]->FindToList(table[HashFunction(str)], str))
            return true;
        return false;
    }

    void DelToTable(string str)
    {
        if (FindToTabel(str))
        {
           table[HashFunction(str)]->DelToList(table[HashFunction(str)], str);
        }
    }
    void Out_Table()
    {   
        for (int i = 0; i < size_table; i++)
        {
            if (table[i] != nullptr)
                cout << i + 1 << " -> "; table[i]->write(table[i]);
        }
    }

private:
    static const int size_table = 37;
    T_List* table[size_table];
};
int main()
{
    HashTable table;
    table.AddInTable();
    table.Out_Table();
   
    return 0;
}
