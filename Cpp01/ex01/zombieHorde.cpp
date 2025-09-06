#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *ZombieObje= new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        ZombieObje[i].setName(name);
    }
    return ZombieObje;
}