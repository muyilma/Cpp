#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie *newClass;
    newClass=newZombie(name);
    newClass->announce();
}