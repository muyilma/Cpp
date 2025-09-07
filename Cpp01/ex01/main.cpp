#include "Zombie.hpp"

int main()
{
    int number=6;
    Zombie *naber;

    naber= zombieHorde(number,"mustafa");
    naber[3].setName("İsmail");
    for (int i = 0; i < number; i++)
        naber[i].announce();
    delete[] naber;
}