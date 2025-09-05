#include "Zombie.hpp"

//YAPAMADIM
int main()
{
    int number=6;
    Zombie *naber;

    naber= zombieHorde(number,"mustafa");
    for (int i = 0; i < number; i++)
    {
        naber[i].announce();
    }
}


