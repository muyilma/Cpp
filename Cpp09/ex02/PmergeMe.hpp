#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>

class PmergeMe
{
    private:    
        std::vector<std::pair<int,int> > vect;
        std::deque<int> deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void parser(int argc,char **argv);
};

#endif