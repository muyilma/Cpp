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
    Zombie();//olsun deöiş evo pagede
    ~Zombie();//evo pagede gördüm yarın bir sor birilerine
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif 