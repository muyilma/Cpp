#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie ZombieObje[N];

    int i=0;
    for (int i = 0; i < N; i++)
    {
        ZombieObje[i].setName(name);
    }
    for (int i = 0; i < N; i++)
    {
        ZombieObje[i].announce();
    }
    return ZombieObje;
}