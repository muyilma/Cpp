#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
    private:

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
};

#endif