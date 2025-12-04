#include "Cat.hpp"

Cat::Cat()
{ 
    std::cout << "Cat Default constructor called" << std::endl;
    type="Cat";
}

Cat::Cat(const Cat& other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meaw!!Meaw!!\n";
}
