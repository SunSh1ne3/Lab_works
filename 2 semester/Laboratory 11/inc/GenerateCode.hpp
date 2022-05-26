#pragma once
#include <iostream>
using namespace std;

enum Lang { Java = 0, C_plus_plus = 1, PhP = 2 };

class CodeGenerator
{
public:
    CodeGenerator(Lang language)
    {
        m_language = language;
        cout << "Base class: constructor " << endl;
    }
    virtual ~CodeGenerator()
    {
        cout << "Base class: destructor " << endl;
    }
    virtual string someCodeRelatedThing() = 0;

protected:
    Lang m_language;
};