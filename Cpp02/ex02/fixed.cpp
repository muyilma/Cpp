#include "fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{ 
    number=0; 
}
Fixed::~Fixed()
{ 

}

void Fixed::setRawBits(int const raw) { number=raw; }

int Fixed::getRawBits( void ) const
{ 
    return number; 
}

Fixed::Fixed(const Fixed &obj)
{
    number=obj.number;
}

Fixed& Fixed::operator=(const Fixed& copy) {
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

bool Fixed::operator>(const Fixed& other) const
{
	return (this->number > other.number);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (number < other.number);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (number >= other.number);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (number <= other.number);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (number == other.number);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (number != other.number);
}

Fixed Fixed::operator+(const Fixed& copy)
{
    return Fixed(toFloat()+copy.toFloat());
}


Fixed Fixed::operator-(const Fixed& copy)
{
    return Fixed(toFloat()-copy.toFloat());
}

Fixed Fixed::operator*(const Fixed& copy)
{
    return Fixed(toFloat()*copy.toFloat());
}

Fixed Fixed::operator/(const Fixed& copy)
{
    return Fixed(toFloat()/copy.toFloat());
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a<b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a>b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a<b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a>b)
        return a;
    return b;
}

Fixed& Fixed::operator++()
{
    number++;
    return *this;
}

Fixed& Fixed::operator--()
{
    number--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);

    number++;
    return temp;
}


Fixed Fixed::operator--(int)
{
    Fixed temp(*this);

    number--;
    return temp;
}
