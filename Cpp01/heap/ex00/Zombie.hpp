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
        
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif 