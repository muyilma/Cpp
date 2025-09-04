#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *newObject;
    newObject=new(Zombie);
    newObject->setName(name);
    return newObject;
}