#include "Zombie.hpp"

Zombie* newZombie( std::string names )
{
    Zombie *newObject=new Zombie(names);
    return newObject;
}