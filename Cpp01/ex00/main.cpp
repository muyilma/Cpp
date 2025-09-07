#include "Zombie.hpp"

int main()
{
    Zombie *zom;

    zom=newZombie("foo");
    zom->announce();
    randomChump("Lorem Amed");
    randomChump("Ahmet Kaya");
    delete zom;
}


