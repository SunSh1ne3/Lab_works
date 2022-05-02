#include <iostream>
#include "inc/Matrix.hpp"
using namespace std;
using namespace math;

int main()
{

	cout << "=== Test 1 ( * ) ===" << endl;
	{
		Mat22d A({ {
		{1,2},
		{3,4}
		} });

		Vec2d X({ {
		{1},
		{1}
		} });

		auto B = A * X;

		assert(B.get(0, 0) == 3);
		assert(B.get(1, 0) == 7);
	}
	cout << "Done!" << endl;

	cout << "=== Test 2(-) === " << endl;
	{
		Mat22d A({ {
		{1,1},
		{1,1}
		} });

		Mat22d X({ {
		{1,2},
		{3,4}
		} });
		auto B = A - X;

		assert(B.get(0, 0) == 0);
		assert(B.get(0, 1) == -1);
		assert(B.get(1, 0) == -2);
		assert(B.get(1, 1) == -3);
	}
	cout << "Done!" << endl;

	cout << "=== Test 3 ( + ) ===" << endl;
	{
		Mat22d A({ {
		{1,1},
		{1,1}
		} });

		Mat22d X({ {
		{1,2},
		{3,4}
		} });

		auto B = A + X;

		assert(B.get(0, 0) == 2);
		assert(B.get(0, 1) == 3);
		assert(B.get(1, 0) == 4);
		assert(B.get(1, 1) == 5);
	}
	cout << "Done!" << endl;

	cout << "=== Test 4 ( Det ) ===" << endl;
	{
		Mat22d A({ {
		{1,2},
		{3,4}
		} });

		Mat33d X({ {
		{1,2,3},
		{4,5,6},
		{7,8,9}
		} });

		assert(A.DET() == -2);
		assert(X.DET() == 0);
	}
	cout << "Done!" << endl;

	cout << "=== Test 5 ( Reverese ) === " << endl;
	{
		Mat22d X({ {
		{1,2},
		{3,4}
		} });
		Mat33d A({ {
		{2,5,7},
		{6,3,4},
		{5,-2,-3},
		} });

		auto B = X.reverse();
		auto C = A.reverse();
		assert(B.get(0, 0) == -2);
		assert(B.get(0, 1) == 1);
		assert(B.get(1, 0) == 1.5);
		assert(B.get(1, 1) == -2);

		assert(C.get(0, 0) == 1);
		assert(C.get(0, 1) == -1);
		assert(C.get(0, 2) == 1);
		assert(C.get(1, 0) == -38);
		assert(C.get(1, 1) == 41);
		assert(C.get(1, 2) == -34);
		assert(C.get(2, 0) == 27);
		assert(C.get(2, 1) == -29);
		assert(C.get(2, 2) == 24);
	}
	cout << "Done!" << endl;

	cout << "=== Test 6 ( Transpposition ) === " << endl;
	{
		Mat22d X({ {
		{1,2},
		{3,4}
		} });
		auto B = X.transposition();
		auto C = X.transposition().transposition();
		assert(B.get(0, 0) == 1);
		assert(B.get(0, 1) == 3);
		assert(B.get(1, 0) == 2);
		assert(B.get(1, 1) == 4);

		assert(C.get(0, 0) == 1);
		assert(C.get(0, 1) == 2);
		assert(C.get(1, 0) == 3);
		assert(C.get(1, 1) == 4);
	}
	cout << "Done!" << endl;

	return 0;
}