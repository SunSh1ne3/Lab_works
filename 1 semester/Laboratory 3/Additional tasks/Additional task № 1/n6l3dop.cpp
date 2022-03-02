#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float s = 0;
	cout << "X" << "       " << "S" << endl << endl;
	for (double x = 0; x <= 1.6; x += 0.1) {	
		for (double n = 1; n <= 20; n++) {
			double y = pow(x, 2 * n - 2) / (2 * n + 1);
			 s = s + y;
		}
		cout << x << "    " << s << endl;
	}
	return 0;


}
