#include "Dog.hpp"

Dog::Dog()
{ 
    std::cout << "Dog Default constructor called" << std::endl;
    type="Dog";
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Hav!!Hav!!\n";
}