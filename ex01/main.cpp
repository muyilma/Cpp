#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

Contact* PhoneBook::getUser(){return user;}
void Contact::setName(std::string ipt) {name = ipt;}
void Contact::setSurName(std::string ipt) {surName = ipt;}
void Contact::setNickName(std::string ipt) { nickName = ipt; }
void Contact::setPhoneNumber(std::string ipt) { phoneNumber = ipt; }
void Contact::setSecret(std::string ipt) { Secret = ipt; }
std::string Contact::getName() { return name; }
std::string Contact::getSurName() { return surName; }
std::string Contact::getNickName() { return nickName; }
std::string Contact::getPhoneNumber() { return phoneNumber; }
std::string Contact::getSecret() { return Secret; }

void PhoneBook::SearchUser(Contact user[8])
{
    int number = 0;
    while (number != 9)
    {
        std::cin >> number;
        if (number == 9)
            break;
        std::cout << "First Name:" << user[number].getName() << std::endl;
        std::cout << "Surname:" << user[number].getSurName() << std::endl;
        std::cout << "Nickname:" << user[number].getNickName() << std::endl;
        std::cout << "Phone Number:" << user[number].getPhoneNumber() << std::endl;
        std::cout << "Dark Secret İnfo:" << user[number].getSecret() << std::endl;
    }
}


void clear_screen()
{
    std::cout << "[H[2J[3J";
}

void error_handle_long(std::string nbr)
{
    (void)nbr;
}




void PhoneBook::UserAdd(Contact user[8], int *i)
{
    std::string str;

    std::cout << "First Name:";
    std::cin >> str;
    user[*i].setName(str);

    std::cout << "Surname:";
    std::cin >> str;
    user[*i].setSurName(str);

    std::cout << "nickname:";
    std::cin >> str;
    user[*i].setNickName(str);

    std::cout << "Phone Number:";
    std::cin >> str;
    error_handle_long(str);
    user[*i].setPhoneNumber(str);

    std::cout << "Dark Secret İnfo:";
    std::cin >> str;
    user[*i].setSecret(str);

    (*i)++;
    if (*i == 8)
        *i = 0;
}

int main()
{
    PhoneBook cont;
    std::string name = "";
    int i = 0;

    while (1)
    {
        std::cout << "ADD    SEARCH     EXIT\n";
        if (!(std::cin >> name))
            break;
        if (name == "ADD")
            cont.UserAdd(cont.getUser(),&i);
        else if (name == "SEARCH")
            cont.SearchUser(cont.getUser());
        else if (name == "EXIT")
            break;
        else
        {
            clear_screen();
            std::cout << "Wrong input!!!  " << name << std::endl;
            continue;
        }
        clear_screen();
    }
}
