#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap : public FragTrap
{
    private:

    public:
        FragTrap();
        ~FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        void highFivesGuys(void);
};

#endif