#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> db;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void input_exec(std::string input);
        bool count_parser(const std::string& count_str, float& val);
        bool date_parser(const std::string& date);
    };

#endif