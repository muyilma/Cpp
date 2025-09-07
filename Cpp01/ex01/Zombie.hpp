#ifndef ZOMBIE
#define ZOMBIE

#include <string>

class Zombie
{
    private://evo pagede defult constructor istiyor olmaı mı?
        std::string names;
    public:
        void announce( void );
        void setName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif 