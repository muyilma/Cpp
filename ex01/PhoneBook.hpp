#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact user[8];
    public:
        Contact* getUser();
        void UserAdd(Contact user[8],int *i);
        void SearchUser(Contact user[8]);
};
void clear_screen();
#endif 