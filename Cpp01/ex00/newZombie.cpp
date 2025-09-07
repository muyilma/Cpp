#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *newObject;//evo pagede burada constucter kullanmamı istemiş doğru mu sor?
    newObject=new(Zombie);
    newObject->setName(name);
    return newObject;
}