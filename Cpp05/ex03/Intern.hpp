#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    private:
        AForm* createShrubbery(const std::string& target);
        AForm* createRobotomy(const std::string& target);
        AForm* createPresidential(const std::string& target);
    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        AForm* makeForm(const std::string& name, const std::string& target);
};

#endif