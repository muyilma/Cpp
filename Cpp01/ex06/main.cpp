#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc!=2)
        return 1;

    Harl h;
    h.complain(argv[1]);
}
