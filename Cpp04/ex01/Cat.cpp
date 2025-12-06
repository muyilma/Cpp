#include "Cat.hpp"

Cat::Cat()
{ 
    brain=new Brain();
    type="Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    brain=new Brain(*other.brain);
    type=other.type;
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        type=other.type;
        delete brain;
        brain=new Brain(*other.brain);
    }
    std::cout << "Cat Copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meaw!!Meaw!!\n";
}

void Cat::setIdeas(std::string idea) const
{
    brain->setIdeas(idea);
}

std::string Cat::getIdeas() const
{ 
    return brain->getIdeas();
}
