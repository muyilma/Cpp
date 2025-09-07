#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *newObject=new Zombie(name);
    return newObject;
}