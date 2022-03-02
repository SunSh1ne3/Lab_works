#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    setlocale(LC_ALL,"Rus");
    int last;
    
    int n; cin >> n;
    if (n > 0) {
        if (n > 9) {
            int first = n % 10;
            int lenght = 1;
            int x=n;
            while (x > 10)
            {
                x = x / 10;
                last = x;
                lenght++;
            }
            if (lenght < 3)
            {
                cout << first << last;
            }
            else
            {
                int p = pow(10, lenght - 1);
                int t = (n % p) / 10;
                cout << first << t << last;
            }
        }
        else
        {
            cout << n;
        }
    }
    else
        cout << "Число не подходит";
    
    return 0;
}