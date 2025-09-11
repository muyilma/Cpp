#include "fixed.hpp"
#include <iostream>

Fixed::Fixed()
{ 
    std::cout << "Default constructor called" << std::endl;
    number=0; 
}
Fixed::~Fixed(){ std::cout << "Destructor called" << std::endl;}
void Fixed::setRawBits(int const raw) { number=raw; }

int Fixed::getRawBits( void ) const
{ 
    std::cout << "getRawBits member function called" << std::endl;
    return number; 
}

Fixed::Fixed(Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    number=obj.number;
}

Fixed& Fixed::operator=(Fixed& copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {           
        this->number = copy.getRawBits();  
    }
    return *this;          
}
