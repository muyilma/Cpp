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
        void _parser(int argc,char **argv);

        std::vector<std::pair<int,int> > _vect;
        std::deque<int> _deq;
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void run(int argc,char **argv);
        void sort_vector(std::vector< std::pair<int, int> > &_vect);
        void sort_vect_jahnson(bool single, int last);
        
};

#endif