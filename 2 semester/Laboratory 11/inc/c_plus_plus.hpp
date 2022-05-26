#pragma once
#include <GenerateCode.hpp>

    class C_PLUS_PLUS :public CodeGenerator
    {
    public:
        C_PLUS_PLUS(Lang language) :CodeGenerator(language)
        {
            cout << "C_PLUS_PLUS class: constructor " << endl;
        }
        virtual ~C_PLUS_PLUS()
        {
            cout << "C_PLUS_PLUS class: destructor " << endl;
        }
        string someCodeRelatedThing() override
        {
            return "C_PLUS_PLUS code";
        }
    };
