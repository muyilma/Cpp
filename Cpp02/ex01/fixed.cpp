#include "fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{ 
    std::cout << "Default constructor called" << std::endl;
    number=0; 
}
Fixed::~Fixed(){ std::cout << "Destructor called" << std::endl;}
void Fixed::setRawBits(int const raw) { number=raw; }

int Fixed::getRawBits( void ) const
{ 
    return number; 
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    number=obj.number;
}

Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {           
        this->number = copy.getRawBits();  
    }
    return *this;          
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) 
{
    os << obj.toFloat();
    return os;
}

Fixed::Fixed(const int number)
{
    this->number=number << bitNumber ;
}

Fixed::Fixed(const float number)
{
    this->number=roundf(number *(1<< bitNumber));
}

float Fixed::toFloat( void ) const
{
    return (float)this->number / (1 << this->bitNumber);
}

int Fixed::toInt( void ) const
{
        return this->number >> this->bitNumber;
}
