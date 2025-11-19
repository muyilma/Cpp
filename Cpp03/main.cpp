#include <iostream>

class ClapTrap
{
    private:
        int aaaaaaaaaaaaaaaa;
    protected:
        int HitPoints;
        int AttackDamage;
    public:
        ClapTrap()
        {
            HitPoints=10;
            AttackDamage=11;
        }
        int getHitD(){return HitPoints;}
        void setHitD(int a){HitPoints=a;}
};

class ScavTrap : public ClapTrap
{
    protected:
    int HitPoints;
    int AttackDamage;
    int getHit(){return HitPoints;}
    void setHit(int a){HitPoints=a;}
    public:
        ScavTrap()
        {
            HitPoints=ClapTrap::HitPoints;
            AttackDamage=11;
        }
};

int main()
{
    ClapTrap a;
    ScavTrap b;

    std::cout << "a:" << a.getHitD() << "\n";
    std::cout << "b:" << b.getHitD() << "\n";
}
