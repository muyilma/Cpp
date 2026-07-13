#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{ 
    std::ifstream file("data.csv");
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file => data.csv" << std::endl;
        exit(EXIT_FAILURE); 
    }

    std::string date;
    std::string price;
    
    if (std::getline(file, date)) {
    }

    while (1) {
        
        if (!std::getline(file,date,','))
            break;
        if (std::getline(file,price))
        {
            float pricef = strtof(price.c_str(), NULL);
            db[date] = pricef;
        }
    }

    file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
       this->db = other.db;
    }
    
    return *this;
}


void BitcoinExchange::dataPrint()
{
    std::map<std::string, float>::iterator it;


    for (it = db.begin(); it != db.end(); ++it) {
        std::cout << "Tarih: " << it->first << " | Fiyat: " << it->second << std::endl;
    }
}
bool BitcoinExchange::date_parser(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        std::cerr << "Error: bad input => " << date << std::endl;
        return true;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return true;
    }

    // Basit gün-ay mantık kontrolü (Şubat, 30 çeken aylar vs.)
    if ((day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) ||
        (day > 29 && month == 2)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return true;
    }

    return false;
}

bool BitcoinExchange::count_parser(const std::string& count_str, float& val)
{
    char *endptr;
    double d_val = std::strtod(count_str.c_str(), &endptr);

    if (d_val < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return true;
    }
    if (d_val > 1000.0) {
        std::cerr << "Error: too large a number." << std::endl;
        return true;
    }
    
    val = static_cast<float>(d_val);
    return false;
}

void BitcoinExchange::input_exec(std::string input)
{
    std::ifstream file(input.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file => " << input << std::endl;
        exit(EXIT_FAILURE); 
    }
    std::string date;
    std::string count;

    if (std::getline(file, date)) {
    }

    while (1) {
        
        if (!std::getline(file,date,'|'))
            break;

        while (!date.empty()  && date[date.size() - 1] == ' ')   
            date.erase(date.size() - 1);
        if (date_parser(date))
            continue;
        float countf;
        if (std::getline(file,count))
        {
            while (!count.empty() && count[0] == ' ')                 
                count.erase(0, 1);
                
            countf = strtof(count.c_str(), NULL);
        }
        if(count_parser(count,countf))
            continue;
        
        
        std::cout << date << " ==> " << count << " ==> " << db[date] * countf << std::endl;
    }
    file.close();
}