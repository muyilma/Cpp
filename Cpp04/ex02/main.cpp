#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    
    const Animal* meta[4];
    
    for (int i = 0; i < 2; i++)
        meta[i]=new Dog();
    for (int i = 2; i < 4; i++)
        meta[i]=new Cat();
    std::cout << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "Type: " <<  meta[i]->getType() << std::endl;
        std::cout << "makeSound: ";
        meta[i]->makeSound();
    }
    for (int i = 0; i < 4; i++)
        delete meta[i];

    std::cout << std::endl;
    Cat* parent=new Cat();
    parent->setIdeas("I'm hungry");
    Cat* child =new Cat(*parent);
    
    std::cout << std::endl;
    std::cout << "parent: " <<  parent->getIdeas() << std::endl;
    std::cout << "child: " <<  child->getIdeas() << std::endl;
    std::cout << std::endl;

    parent->setIdeas("I'm not hungry");
    std::cout << std::endl;
    std::cout << "parent: " <<  parent->getIdeas() << std::endl;
    std::cout << "child: " <<  child->getIdeas() << std::endl;
    std::cout << std::endl;

    delete parent;
    delete child;
}