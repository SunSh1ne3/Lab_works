
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Вариант 6.1" << endl << "Ввести натуральные числа A, B и C. Если A меньше B и B больше C, то вывести B+A-C, в противном случае если B кратно C, то вывести B/С-B, в остальных случаях вывести A*B-C" << endl;
    cout << "Введите A,B,C" << endl;
    int A, B, C; cin >> A >> B >> C;
    if ((A < 1) || (B < 1) || (C < 1)) {
        if ((A < B) && (B > C)) 
        {
            cout << B + A - C;
        }
        else if ((B % C) == 0)
        {
            cout << (B / C - B);
        }
        else
        {
            cout << (A * B - C);
        }
    }
    else
    {
        cout << "Данные не подходят условию.";
    }
    return 0;
}