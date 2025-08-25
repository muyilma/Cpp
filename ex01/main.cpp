#include "Contact.hpp"
#include <cstdlib> 

void clear_screen() {
    std::cout << "\033[2J\033[1;1H";
}
   
void error_handle_long(std::string nbr)
{
    (void)nbr;
}
void input_user_info(Contact user[8])
{
    std::string str;
    long nbr;
    
    std::cout << "First Name:";
    std::cin >> str;
    user[0].setName(str);
    
    std::cout << "Surname:";
    std::cin >> str;
    user[0].setSurName(str);

    std::cout << "nickname:";
    std::cin >> str;
    user[0].setNickName(str);
    
    std::cout << "Phone Number:";
    std::cin >> str;
    error_handle_long(str);
    user[0].setPhoneNumber(str);

    std::cout << "Dark Secret İnfo:";
    std::cin >> str;
    user[0].setSecret(str);
}

void find_user_info(Contact user[8])
{
    int index=0;
    while (index!=9)
    {
        std::cin >> index;
        std::cout << "First Name:" << user[0].getName() << std::endl;
        std::cout << "Surname:" << user[0].getSurName() << std::endl;
        std::cout << "Nickname:" << user[0].getNickName() << std::endl;
        std::cout << "Phone Number:" << user[0].getPhoneNumber() << std::endl;
        std::cout << "Dark Secret İnfo:" << user[0].getSecret() << std::endl;
    }
}

int main()
{
    Contact user[8];
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