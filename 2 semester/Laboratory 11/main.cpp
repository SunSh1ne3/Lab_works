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

    CodeGenerator* code1 = generateCode(PhP);
    cout << code1->someCodeRelatedThing() << endl;

    cout << "  ====   c_plus_plus   ====  " << endl;

    CodeGenerator* code2 = generateCode(C_plus_plus);
    cout << code2->someCodeRelatedThing() << endl;

    delete code;
    delete code1;
    delete code2;
	return 0;
}