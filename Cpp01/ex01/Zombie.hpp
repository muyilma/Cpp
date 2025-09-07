#ifndef ZOMBIE
#define ZOMBIE

#include <string>

class Zombie
{
    private:
        std::string names;
    public:
        void announce( void );
        void setName(std::string name);
    Zombie();
};  

Zombie* zombieHorde( int N, std::string name );

#endif 