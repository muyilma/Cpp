#include <iostream>
#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burgerımde ekstra domuz pastırması olması çok hoşuma gidiyor. Gerçekten de!" << std::endl;
}

void Harl::info()
{
    std::cout << "Ekstra domuz pastırması için daha fazla para ödenmesine inanamıyorum. Burgerımde yeterince domuz pastırması koymadınız! Koysaydınız, daha fazlasını istemezdim!" << std::endl;
}

void Harl::warning()
{
    std::cout << "Bence ücretsiz ekstra domuz pastırması hak ediyorum. Yıllardır geliyorum, oysa sen burada çalışmaya geçen ay başladın." << std::endl;
}

void Harl::error()
{
    std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levelSeries[] = {"DEBUG","INFO","WARNING","ERROR"};
    void (Harl::*functions[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++)
    {
        if (levelSeries[i]==level)
         (this->*functions[i])();
    }    
}