#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    string arr[100];
    //int k = 0;
    int count = 0;
    ifstream in("int.txt");
    ofstream out("out.txt");
    //string zn = "!? ,.";
    //string s;
    int i1 = 0;
    while (!in.eof()) 
    {
        in >> arr[i1];
        i1++;
        count++;
    }
    cout << count;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << endl;
    }


    /*
    while (!in.eof())
    {
        for (int i = 0; i < s.size(); i++)
        {
            for (int b = 0; b < 5; b++)
            {
                while (s != zn)
                {
                   k++;
                }
            }
            
        }
        
    }
    cout << k;*/
}