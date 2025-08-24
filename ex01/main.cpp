#include "user.hpp"
#include <cstdlib> 

void clear_screen() {
    std::cout << "\033[2J\033[1;1H";
}
   
void input_user_info(contact user[8])
{
    std::cout << "First Name:";
    std::cin >> user[0].name;

    std::cout << "Surname:";
    std::cin >> user[0].surName;

    std::cout << "nickname:";
    std::cin >> user[0].nickName;

    std::cout << "Phone Number:";
    std::cin >> user[0].phoneNumber;

    std::cout << "Dark Secret İnfo:";
    std::cin >> user[0].Secret;
}

void find_user_info(contact user[8])
{
    std::cout << "First Name:" << user[0].name << std::endl;
    std::cout << "Surname:" << user[0].surName << std::endl;
    std::cout << "Nickname:" << user[0].nickName << std::endl;
    std::cout << "Phone Number:" << user[0].phoneNumber << std::endl;
    std::cout << "Dark Secret İnfo:" << user[0].Secret << std::endl;

}

int main()
{
    contact user[8];
    std::string name="";
    
    while (1)
    {
        std::cout << "ADD    SEARCH     EXIT\n";
        std::cin >> name; 
        if (name=="ADD")
            input_user_info(user);
        else if(name=="SEARCH")
            find_user_info(user);
        else if (name=="EXIT")
            break;
        else
            std::cout << "Wrong input!!!" << name << std::endl;

            clear_screen();
    }
}