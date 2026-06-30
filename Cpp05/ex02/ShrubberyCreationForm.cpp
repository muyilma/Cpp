#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",false,145,137), target("anonymous")
{ 
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name)  : AForm("ShrubberyCreationForm",false,145,137), target(name)
{
}

void ShrubberyCreationForm::executeAction() const
{
    std::string fileName = this->target + "_shrubbery";
    std::ofstream outFile(fileName.c_str());

    if (!outFile.is_open())
    {
        std::cerr << "Hata: " << fileName << " dosyasi olusturulamadi!" << std::endl;
        return;
    }

    outFile << "         v" << std::endl;
    outFile << "        >X<" << std::endl;
    outFile << "         A" << std::endl;
    outFile << "        d$b" << std::endl;
    outFile << "      .d\\$$b." << std::endl;
    outFile << "    .d$i$$\\$$b." << std::endl;
    outFile << "       d$$@b" << std::endl;
    outFile << "      d\\$$$ib" << std::endl;
    outFile << "    .d$$$\\$$$b" << std::endl;
    outFile << "  .d$$@$$$$\\$$ib." << std::endl;
    outFile << "      d$$i$$b" << std::endl;
    outFile << "     d\\$$$$@$b" << std::endl;
    outFile << "  .d$@$$\\$$$$$@b." << std::endl;
    outFile << ".d$$$$i$$$\\$$$$$$b." << std::endl;
    outFile << "        ###" << std::endl;
    outFile << "        ###" << std::endl;
    outFile << "        ###" << std::endl;

    outFile.close();
}