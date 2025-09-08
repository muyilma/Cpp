#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
    private:
        std::string name;
    public:
        void announce( void );
        void setName(std::string setName);
        Zombie();
};  

Zombie* zombieHorde( int N, std::string name );

#endif 