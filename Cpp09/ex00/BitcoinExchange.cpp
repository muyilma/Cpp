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

    if ((day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)) ||
        (day > 29 && month == 2)) {
        std::cerr << "Error: bad input => " << date << std::endl;
        return true;
    }

    return false;
}

bool BitcoinExchange::count_parser(const std::string& count_str, float& val)
{
    if (count_str.empty()) {
        std::cerr << "Error: bad input => empty value" << std::endl;
        return true;
    }

    char *endptr;
    float d_val = strtof(count_str.c_str(), &endptr);

    if (count_str.c_str() == endptr || *endptr != '\0') {
        std::cerr << "Error: bad input => " << count_str << std::endl;
        return true;
    }

    if (d_val < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return true;
    }
    if (d_val > 1000.0f) {
        std::cerr << "Error: too large a number." << std::endl;
        return true;
    }
    
    val = d_val;
    return false;
}

void BitcoinExchange::input_exec(std::string input)
{
    std::ifstream file(input.c_str());
    
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file => " << input << std::endl;
        exit(EXIT_FAILURE); 
    }
    std::string line;

    if (std::getline(file, line)) {
    }

    while (std::getline(file,line)) {

        if (line.empty()) continue;
        
        size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pipe_pos);
        std::string count = line.substr(pipe_pos + 1);

        while (!date.empty() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t' || date[date.size() - 1] == '\r')) 
            date.erase(date.size() - 1);
        while (!date.empty() && (date[0] == ' ' || date[0] == '\t' || date[0] == '\r')) 
            date.erase(0, 1);

        while (!count.empty() && (count[count.size() - 1] == ' ' || count[count.size() - 1] == '\t' || count[count.size() - 1] == '\r')) 
            count.erase(count.size() - 1);
        while (!count.empty() && (count[0] == ' ' || count[0] == '\t' || count[0] == '\r')) 
            count.erase(0, 1);

        if (date_parser(date))
            continue;
        
        float countf = 0.0f;
        countf = strtof(count.c_str(), NULL);
        
        if(count_parser(count,countf))
            continue;
        std::map<std::string, float>::iterator it = db.upper_bound(date);
        
        if (it == db.begin()) {
            std::cerr << "Error: Date too early, no data available => " << date << std::endl;
            continue;
        }
        
        --it; 
        float exchange_rate = it->second;
    std::cout << date << " => " << count << " = " << (countf * exchange_rate) << std::endl;    }
    file.close();
}