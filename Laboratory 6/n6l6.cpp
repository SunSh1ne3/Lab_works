#include <fstream>
#include <iostream>
#define N =10000;
using namespace std;

/*void Sort(int n, int mas[10000])
{

}*/

int main()
{
    int n; cin >> n;
    int mas[10000][10000];
    ifstream in("int.txt");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> mas[i][j];
        }
    }
}