#pragma once
#include <iostream>
#include <php.hpp>
#include <java.hpp>
#include <c_plus_plus.hpp>
#include <GenerateCode.hpp>

    CodeGenerator* generateCode(Lang language)
    {
        CodeGenerator* shift = nullptr;
        switch (language)
        {
        case Java:
        {
            shift = new JAVA(language);
            shift->someCodeRelatedThing();
            return shift;
        }
        case C_plus_plus:
        {
            shift = new C_PLUS_PLUS(language);
            shift->someCodeRelatedThing();
            return shift;
        }
        case PhP:
        {
            shift = new PHP(language);
            shift->someCodeRelatedThing();
            return shift;
        }
        }
    }
