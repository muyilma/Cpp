#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>

Contact *PhoneBook::getUser() { return user; }
void Contact::setName(std::string ipt) { name = ipt; }
void Contact::setSurName(std::string ipt) { surName = ipt; }
void Contact::setNickName(std::string ipt) { nickName = ipt; }
void Contact::setPhoneNumber(std::string ipt) { phoneNumber = ipt; }
void Contact::setSecret(std::string ipt) { Secret = ipt; }
std::string Contact::getName() { return name; }
std::string Contact::getSurName() { return surName; }
std::string Contact::getNickName() { return nickName; }
std::string Contact::getPhoneNumber() { return phoneNumber; }
std::string Contact::getSecret() { return Secret; }

void clear_screen()
{
    std::cout << "[H[2J[3J";
}

int error_handle_long(std::string nbr)
{
    for (int i = 0; nbr[i]; i++)
    {
        if (!(nbr[i] >= '0' && nbr[i] <= '9'))
            return 0;
    }
    return 1;
}

std::string print(std::string str)
{
    std::string newstr="";
    if (str.empty())
        return "";
    if (str.size() <= 10)
        return str;
    for (int i = 0; i < 10; i++)
    {
        if (i==9)
            newstr+='.';
        else
            newstr+=str[i];
    }
    return newstr;
}

int error_handle_search(std::string nbr)
{
    for (int i = 0; nbr[i]; i++)
    {
        if (!(nbr[i] > '0' && nbr[i] <= '9'))
            return 0;
        if (i == 1)
            return 0;
    }
    return 1;
}
void search_display(Contact user[8])
{
    clear_screen();
    std::cout << std::setfill('-') << std::setw(46) << "\n";
    std::cout << "|" << "     " << "index" << "|" << " FirstName" << "|" << "   Surname" << "|" << "  Nickname" << "|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setfill('-') << std::setw(46) << "\n";
        std::cout << "|" << std::setfill(' ') << std::setw(10) << i+1 << "|" << std::setw(10) << print(user[i].getName()) << "|" << std::setw(10) << print(user[i].getSurName() )<< "|" << std::setw(10) << print(user[i].getNickName()) << "|" << std::endl;
    }
    std::cout << std::setfill('-') << std::setw(46) << "\n";
    std::cout << "|"<< std::setfill(' ')  << std::setw(43) << "Write 9 to return" << "|" << std::endl;
    std::cout << std::setfill('-') << std::setw(46) << "\n";
}

int user_check(Contact user)
{
    if (!(user.getName().empty()))
        return 0;
    if (!(user.getNickName().empty()))
        return 0;
    if (!(user.getSurName().empty()))
        return 0;
    if (!(user.getSecret().empty()))
        return 0;
    if (!(user.getPhoneNumber().empty()))
        return 0;
    return 1;
}
void PhoneBook::SearchUser(Contact user[8])
{
    std::string number = "-1";
    int index=-1;

    search_display(user);
    while (number != "9")
    {
        std::cout << "Search İndex:";
        if (!std::getline(std::cin, number))
            exit(1);
        if (number.empty() || !error_handle_search(number))
            continue;
        index=atoi(number.c_str()) - 1;    
        if (number == "9")
            break;
        if (user_check(user[index]))
        {
            continue;
        }
        std::cout << "First Name:" << user[index].getName() << std::endl;
        std::cout << "Surname:" << user[index].getSurName() << std::endl;
        std::cout << "Nickname:" << user[index].getNickName() << std::endl;
        std::cout << "Phone Number:" << user[index].getPhoneNumber() << std::endl;
        std::cout << "Dark Secret İnfo:" << user[index].getSecret() << std::endl;
    }
}

void PhoneBook::UserAdd(Contact user[8], int *i)
{
    std::string str;

    std::cout << "First Name:";
    if (!getline(std::cin, str))
        exit(0);
    user[*i].setName(str);
    std::cout << "Surname:";
    if (!getline(std::cin, str))
        exit(0);
    user[*i].setSurName(str);
    std::cout << "nickname:";
    if (!getline(std::cin, str))
        exit(0);
    user[*i].setNickName(str);
    while (1)
    {
        std::cout << "Phone Number:";
        if (!getline(std::cin, str))
            exit(0);
        if (error_handle_long(str))
        {
            user[*i].setPhoneNumber(str);
            break;
        }
        std::cout << "is not digit\n";
    }
    std::cout << "Dark Secret İnfo:";
    if (!getline(std::cin, str))
        exit(0);
    user[*i].setSecret(str);
    (*i)++;
    if (*i == 8)
        *i = 0;
}

void selection_screan()
{
    std::cout << std::setfill('-') << std::setw(25) << "\n";
    std::cout << "| ADD | SEARCH | EXIT  |\n";
    std::cout << std::setfill('-') << std::setw(25) << "\n";
    std::cout << "İnput:";
}

int main()
{
    PhoneBook cont;
    std::string name = "";
    int i = 0;

    while (1)
    {
        selection_screan();
        if (!std::getline(std::cin, name))
            break;
        if (name == "ADD")
            cont.UserAdd(cont.getUser(), &i);
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
