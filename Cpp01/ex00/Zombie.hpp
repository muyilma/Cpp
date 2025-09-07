#ifndef ZOMBIE
#define ZOMBIE

#include <string>

class Zombie
{
    private:
        std::string names;
    public:
        void announce( void );
    Zombie(std::string name);
    ~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif 