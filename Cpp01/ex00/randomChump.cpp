#include "Zombie.hpp"

void randomChump( std::string names )
{
    Zombie newClass(names);
    newClass.announce();
}