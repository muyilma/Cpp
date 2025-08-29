#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iomanip>

void clear_screen()
{
    std::cout << "[H[2J[3J";
}

void selection_screan()
{
    std::cout << std::setfill('-') << std::setw(25) << "\n";
    std::cout << "| ADD | SEARCH | EXIT  |\n";
    std::cout << std::setfill('-') << std::setw(25) << "\n";
    std::cout << "Input:";
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
