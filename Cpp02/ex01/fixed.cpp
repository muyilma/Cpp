#include "fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    number = obj.number;
}

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->number = number << bitNumber;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->number = roundf(number * 256);
}

void Fixed::setRawBits(int const raw)
{
    number = raw;
}

int Fixed::getRawBits(void) const
{
    return number;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        this->number = copy.getRawBits();
    return *this;
}

std::ostream & Fixed::operator<<(std::ostream &os, const Fixed &obj)// Buna bi bak 
{
    os << obj.toFloat();
    return os;
}

float Fixed::toFloat(void) const
{
    return (float)this->number / 256;
}

int Fixed::toInt(void) const
{
    return number >> bitNumber;
}
