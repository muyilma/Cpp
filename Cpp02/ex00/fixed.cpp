#include "fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    number = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    number = obj.number;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return number;
}

void Fixed::setRawBits(int const raw)
{
    number = raw;
}

void Fixed::operator=(Fixed &copy)// void döndürünce zincirleme bozuluyor 1 tane
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        number = copy.getRawBits();
}
