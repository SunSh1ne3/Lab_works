#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class HashTable
{
public:
    HashTable()
    {
        for (int i = 0; i < size_table; i++)
            m_table->push_back("");
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
        if (elements() >= size_table)
        {
            cout << "Size!! \n";
            return;
        }
            
        auto iter = m_table->cbegin();
        int i = HashFunction(str);
        while (i < size_table)
        {
            if (m_table[i].empty())
            {
                m_table->emplace(iter + i, str);
                return;
            }
            else
                i++;
        }
    }

    void Out_Table()
    {
        for (int i = 0; i < size_table; i++)
            if (!m_table->at(i).empty())
            {
                cout << i + 1 << " - " << m_table->at(i) << endl;
            }  
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

    int FindToTabel(string str)
    {
        for (int i = HashFunction(str); i < size_table; i++)
            if (m_table->at(i) == str)
            {
                cout << "Find!! \n"; 
                return i;
                if (i == size_table)
                {
                    cout << "No find! \n"; 
                    break;
                }
            }
    }
    void DelToTable(string str)
    {
        if (FindToTabel(str))
        {
            auto iter = m_table->cbegin();
            m_table->erase(iter + FindToTabel(str));
        }
    }

    int elements()
    {
        int sum = 0;
        for (int i =0; i < size_table; i++)
            if (!m_table[i].empty())
                sum++;
        return sum;
    }

private:
    static const int size_table = 133;
    vector <string> m_table[size_table];
};

int main()
{
    HashTable table;
    table.AddInTable();
    table.Out_Table();

    return 0;
}
