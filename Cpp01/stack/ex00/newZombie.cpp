#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    static Zombie newObject;
    newObject.setName(name);
    return &newObject;
}