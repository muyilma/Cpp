#include "Zombie.hpp"

int main()
{
    Zombie *zom;
    zom=newZombie("foo");
    zom->announce();
    delete zom;
    randomChump("Lorem Amed");
    randomChump("Ahmet Kaya");
}


