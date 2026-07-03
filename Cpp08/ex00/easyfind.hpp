#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <list>

template<typename T>
typename T::iterator easyfind(T& con,int value)
{
    typename T::iterator it = std::find(con.begin(), con.end(), value);

    if (it == con.end())
        throw std::out_of_range("Number is not find");
    
    return it;
}

#endif