#include "Animal.hpp"

Animal::Animal()
{ 
    std::cout << "Animal Default constructor called" << std::endl;
    type="empty";
}

Animal::Animal(const Animal& other)
{
    type=other.type;
    std::cout << "Animal Copy constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        type=other.type;
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return *this;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound\n";
}