#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data myData;
    myData.price = 42.42f;

    std::cout << "--- ORGINAL DATA ---" << std::endl;
    std::cout << "Data adresses  : " << &myData << std::endl;
    std::cout << "Data price   : " << myData.price << "f" << std::endl;
    std::cout << "---------------------" << std::endl << std::endl;


    uintptr_t rawPtr = Serializer::serialize(&myData);

    std::cout << "--- SERIALIZATION ---" << std::endl;
    std::cout << "Serialize (uintptr_t) value: " << rawPtr << std::endl;
    std::cout << "---------------------" << std::endl << std::endl;


    Data* deserializedData = Serializer::deserialize(rawPtr);

    std::cout << "--- DESERIALIZED DATA ---" << std::endl;
    std::cout << "New Data adresses : " << deserializedData << std::endl;
    std::cout << "New Data price  : " << deserializedData->price << "f" << std::endl;
    std::cout << "-------------------------" << std::endl << std::endl;


    std::cout << "--- TEST RESULT ---" << std::endl;
    if (&myData == deserializedData)
        std::cout << "[Sucsess] " << std::endl;
    else
        std::cout << "[Error]" << std::endl;

    return 0;
}