#include <iostream>
#include <BMP.hpp>
using namespace std;
using namespace image;
int main()
{
    try
    {
        BMP test_bmp(200, 100);
        test_bmp.Fill({ 0,255,0 });
        test_bmp.Rotate(acos(-1) / 2);
        test_bmp.Save("test.bmp");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	return 0;
}