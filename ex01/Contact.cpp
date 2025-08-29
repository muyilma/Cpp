#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <cstdlib>

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

std::string print(std::string str)
{
    std::string newstr = "";
    if (str.empty())
        return "";
    if (str.size() <= 10)
        return str;
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            newstr += '.';
        else
            newstr += str[i];
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

int error_handle_long(std::string nbr)
{
    for (int i = 0; nbr[i]; i++)
    {
        if (!(nbr[i] >= '0' && nbr[i] <= '9'))
            return 0;
    }
    return 1;
}

void search_display(Contact user[8])
{
    clear_screen();

    std::cout << std::setfill('-') << std::setw(46) << "\n";
    std::cout << "|" << "     " << "index" << "|"
              << " FirstName" << "|"
              << "   Surname" << "|"
              << "  Nickname" << "|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << std::setfill('-') << std::setw(46) << "\n";
        std::cout << "|" << std::setfill(' ') << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << print(user[i].getName()) << "|"
                  << std::setw(10) << print(user[i].getSurName()) << "|"
                  << std::setw(10) << print(user[i].getNickName()) << "|"
                  << std::endl;
    }
    std::cout << std::setfill('-') << std::setw(46) << "\n";
    std::cout << "|" << std::setfill(' ') << std::setw(43) << "Write 9 to return" << "|" << std::endl;
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

std::string read_terminal(std::string str_out)
{
    std::string str;

    while (str.empty())
    {
        std::cout << str_out;
        if (!getline(std::cin, str))
            exit(0);
    }
    return str;
}

void PhoneBook::SearchUser(Contact user[8])
{
    std::string number = "-1";
    int index = -1;

    search_display(user);
    while (number != "9")
    {
        number = read_terminal("Search Index:");
        if (!error_handle_search(number))
            continue;
        index = atoi(number.c_str()) - 1;
        if (number == "9")
            break;
        if (user_check(user[index]))
            continue;
        std::cout << "First Name:" << user[index].getName() << std::endl;
        std::cout << "Surname:" << user[index].getSurName() << std::endl;
        std::cout << "Nickname:" << user[index].getNickName() << std::endl;
        std::cout << "Phone Number:" << user[index].getPhoneNumber() << std::endl;
        std::cout << "Dark Secret Info:" << user[index].getSecret() << std::endl;
    }
}

void PhoneBook::UserAdd(Contact user[8], int *i)
{
    std::string str;

    str = read_terminal("First Name:");
    user[*i].setName(str);
    str = read_terminal("Surname:");
    user[*i].setSurName(str);
    str = read_terminal("nickname:");
    user[*i].setNickName(str);
    while (1)
    {
        str = read_terminal("Phone Number:");
        if (error_handle_long(str))
        {
            user[*i].setPhoneNumber(str);
            break;
        }
        std::cout << "is not digit\n";
    }
    str = read_terminal("Dark Secret Info:");
    user[*i].setSecret(str);
    (*i)++;
    if (*i == 8)
        *i = 0;
}
