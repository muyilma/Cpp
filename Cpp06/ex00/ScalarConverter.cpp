#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits> 
#include <cmath>   

ScalarConverter::ScalarConverter(){ }
ScalarConverter::ScalarConverter(const ScalarConverter& other){ (void)other; }
ScalarConverter::~ScalarConverter(){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){ (void)other; return *this; }

static void convertChar(double val)
{
    std::cout << "char: ";

    if (val < 0 || val > 255 || val != val)
        std::cout << "impossible" << std::endl;
    else if (val < 32 || val == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
}

static void convertInt(double val)
{
    std::cout << "int: ";
    if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max() || val != val)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(val) << std::endl;
}

static void convertFloat(double val)
{
    std::cout << "float: ";
    float fVal = static_cast<float>(val);
    
    if (fVal - static_cast<int>(fVal) == 0)
        std::cout << fVal << ".0f" << std::endl;
    else
        std::cout << fVal << "f" << std::endl;
}

static void convertDouble(double val)
{
    std::cout << "double: ";
    
    if (val - static_cast<int>(val) == 0)
        std::cout << val << ".0" << std::endl;
    else
        std::cout << val << std::endl;
}

void ScalarConverter::convert(std::string ltr)
{
    std::string pseudo[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    for (int i = 0; i < 6; i++)
    {
        if (ltr == pseudo[i])
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;

            std::string f_val = (i < 3) ? pseudo[i] : pseudo[i] + "f";
            std::string d_val = (i >= 3) ? pseudo[i] : pseudo[i].substr(0, pseudo[i].length() - 1);
            
            std::cout << "float: " << f_val << std::endl;
            std::cout << "double: " << d_val << std::endl;
            return; 
        }
    }

    if (ltr.length() == 1 && !isdigit(ltr[0]))
    {
        double charVal = static_cast<double>(ltr[0]);
        convertChar(charVal);
        convertInt(charVal);
        convertFloat(charVal);
        convertDouble(charVal);
        return;
    }

    char *endPtr;
    double val = std::strtod(ltr.c_str(), &endPtr);

    if (*endPtr != '\0' && *endPtr != 'f')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    convertChar(val);
    convertInt(val);
    convertFloat(val);
    convertDouble(val);
}