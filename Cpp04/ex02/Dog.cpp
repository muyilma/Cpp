#include "Dog.hpp"

Dog::Dog()
{ 
    brain=new Brain();
    type="Dog";
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
    brain=new Brain(*other.brain);
    type=other.type;
    std::cout << "Dog Copy constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        type=other.type;
        delete brain;
        brain=new Brain(*other.brain);
    }
    std::cout << "Dog Copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Hav!!Hav!!\n";
}

void Dog::setIdeas(std::string idea) const
{
    brain->setIdeas(idea);
}

std::string Dog::getIdeas() const
{ 
    return brain->getIdeas();
}
