#include <cstdlib>
#include <iomanip>

#include <string>
#include <iostream>
int main()
{
    std::string str="";
    str[0]+='a';
    str[1]+='c';
    str[2]+='b';
    str[3]+='d';
    str[4]+='\0';
    std::cout << str;
}   
