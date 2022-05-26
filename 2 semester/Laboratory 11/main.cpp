#include <iostream>
#include <SomeFunctions.hpp>
#include <php.hpp>
#include <c_plus_plus.hpp>
#include <java.hpp>
#include <GenerateCode.hpp>

using namespace std;

int main()
{
    cout << "  ====   java   ====  " << endl;
    CodeGenerator * code = generateCode(Java) ;
    cout << code->someCodeRelatedThing() << endl;

    cout << "  ====   php   ====  " << endl;

    CodeGenerator* code_1 = generateCode(PhP);
    cout << code_1->someCodeRelatedThing() << endl;

    cout << "  ====   c_plus_plus   ====  " << endl;

    CodeGenerator* code_2 = generateCode(C_plus_plus);
    cout << code_2->someCodeRelatedThing() << endl;
	return 0;
}