
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Сколько чисел?" << endl;
    int n; cin >> n;
    if (n < 1) {
        int A[1000], sum[1000], P[1000]; //P-произведение
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            sum[i] = 0;
            P[i] = 1;
            int x = A[i];
            while (x > 0) {
                sum[i] += x % 10;
                x /= 10;
            }
           
            while (x > 0) {
                P[i] *= x % 10;
                x /= 10;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                if ((sum[i] > sum[j]) || ((sum[i] == sum[j]) && (P[i] > P[j])) ||
                    ((sum[i] == sum[j]) && (P[i] == P[j]) && (A[i] > A[j]))) {
                    swap(sum[i], sum[j]);
                    swap(A[i], A[j]);
                    swap(P[i], P[j]);
                }
            }
        for (int i = 0; i < n; i++)
            cout << A[i] << " ";
    }
    else
        cout << "Error" << endl;
    return 0;
}