#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
   
    std::cout << std::endl;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;

    delete i;
    delete j;
    delete meta;

    std::cout << std::endl;

    const WrongAnimal* WrongA = new WrongAnimal();
    const WrongAnimal* WrongC = new WrongCat();
    const WrongCat* WrongCa = new WrongCat();

    std::cout << WrongA->getType() << " " << std::endl;
    std::cout << WrongC->getType() << " " << std::endl;
    WrongA->makeSound();
    WrongC->makeSound();
    WrongCa->makeSound();
    delete WrongCa;
    delete WrongA;
    delete WrongC;
    return 0;
}