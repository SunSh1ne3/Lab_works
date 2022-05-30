#pragma once
#include <GenerateCode.hpp>

using namespace std;


    class PHP :public CodeGenerator
    {
    public:
        PHP(Lang language) :CodeGenerator(language)
        {
            cout << "PHP class: constructor " << endl;
        }
        virtual ~PHP()
        {
            cout << "PHP class: destructor " << endl;
        }
        string someCodeRelatedThing() override
        {
            return "PHP code";
        }
    };
