#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> numbers(5);
    std::cout << "Size: " << numbers.size() << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n\n";

    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = (i + 1) * 10; 
    }
    std::cout << "New Elements: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "==========================================" << std::endl;
    std::cout << "1. DEEP COPY TEST" << std::endl;
    std::cout << "==========================================" << std::endl;
    Array<int> copyNumbers(numbers);
    copyNumbers[0] = 999;

    std::cout << "Original Array [0]: " << numbers[0] << std::endl;
    std::cout << "Copied Array   [0]: " << copyNumbers[0] <<  std::endl;
    std::cout << "\n";

    std::cout << "==========================================" << std::endl;
    std::cout << "2. BOUNDS CHECKING " << std::endl;
    std::cout << "==========================================" << std::endl;
    try {
        std::cout << "numbers[2]: " << numbers[2] << std::endl;
        std::cout << "numbers[50]:" << numbers[50] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n";

    std::cout << "==========================================" << std::endl;
    std::cout << "3. DIFFERENT TEMPLATE TYPES (STRING TEST)" << std::endl;
    std::cout << "==========================================" << std::endl;
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "42";
    words[2] = "School";

    for (unsigned int i = 0; i < words.size(); i++) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
}