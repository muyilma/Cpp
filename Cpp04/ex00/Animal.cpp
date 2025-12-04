#include "Animal.hpp"

Animal::Animal()
{ 
    std::cout << "Animal Default constructor called" << std::endl;
    type="empty";
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal::~Animal()
{
    delete this;
    std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const
{
    std::cout << "aaaaaaaa\n";
}