#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
    public:
        void announce( void );
    Zombie(std::string names);
    ~Zombie();
};

Zombie* newZombie( std::string names );
void randomChump( std::string names );

#endif 