#pragma once
#include <GenerateCode.hpp>

using namespace std;

    class JAVA :public :: CodeGenerator
    {
    public:
        JAVA(Lang language) :CodeGenerator(language)
        {
            cout << "JAVA class: constructor " << endl;
        }
        virtual ~JAVA()
        {
            cout << "JAVA class: destructor " << endl;
        }
        string someCodeRelatedThing() override
        {
            return "JAVA code";
        }
    };
