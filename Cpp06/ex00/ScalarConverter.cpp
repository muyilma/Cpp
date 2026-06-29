#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits> 
#include <cmath>   
#include <iomanip>

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
    float fVal = static_cast<float>(val);
    
    std::cout << std::fixed << std::setprecision(1) << "float: " << fVal << "f" << std::endl;
}

static void convertDouble(double val)
{
    std::cout << std::fixed << std::setprecision(1) << "double: " << val << std::endl;

}

void ScalarConverter::convert(std::string ltr)
{
    std::string pseudo_float[4] = {"-inff", "+inff", "nanf", "inff"};
    std::string pseudo_double[4] = {"-inf", "+inf", "nan", "inf"};

    for (int i = 0; i < 4; i++)
    {
        if (ltr == pseudo_float[i] || ltr == pseudo_double[i])
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << pseudo_float[i] << std::endl;
            std::cout << "double: " << pseudo_double[i] << std::endl;
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


    if (*endPtr == '\0' || (*endPtr == 'f' && *(endPtr + 1) == '\0'))
    {
        convertChar(val);
        convertInt(val);
        convertFloat(val);
        convertDouble(val);
        return;
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}