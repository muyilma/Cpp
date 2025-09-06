#include <iostream>
#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burgerımde ekstra domuz pastırması olması çok hoşuma gidiyor. Gerçekten de!" << std::endl;
}

void Harl::info()
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "Ekstra domuz pastırması için daha fazla para ödenmesine inanamıyorum. Burgerımde yeterince domuz pastırması koymadınız! Koysaydınız, daha fazlasını istemezdim!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "Bence ücretsiz ekstra domuz pastırması hak ediyorum. Yıllardır geliyorum, oysa sen burada çalışmaya geçen ay başladın." << std::endl;
}

void Harl::error()
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levelSeries[] = {"DEBUG","INFO","WARNING","ERROR"};
    void (Harl::*functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    int i;
    for (i = 0; i < 4; i++)
    {
        if (levelSeries[i]==level)
         i++;break;
    }    
    switch (i)
    {
        case 0:
         (this->*functions[0])();
        case 1:
         (this->*functions[1])();
        case 2:
         (this->*functions[2])();
        case 3:
         (this->*functions[0])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
}