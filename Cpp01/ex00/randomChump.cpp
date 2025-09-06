#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie newClass;
    newClass.setName(name);
    newClass.announce();
}