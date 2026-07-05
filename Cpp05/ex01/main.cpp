#include "Bureaucrat.hpp"

void mointorForms(const Form simple, const Form bigForm, const Form smallForm)
{
    std::cout << "\n---Forms---" << std::endl;
    std::cout << simple << std::endl;
    std::cout << bigForm << std::endl;
    std::cout << smallForm << std::endl;
}

void monitorUsers(const Bureaucrat mustafa, const Bureaucrat boss, const Bureaucrat anonymous)
{
    std::cout << "---Users---" << std::endl;
    std::cout << anonymous << std::endl;
    std::cout << mustafa << std::endl;
    std::cout << boss << std::endl;
}

int main()
{
    try
    {
        Bureaucrat mustafa("Mustafa",112);
        Bureaucrat boss("Boss",1);
        Bureaucrat anonymous;
        monitorUsers(mustafa,boss,anonymous);
        
        Form bigForm("bigForm",false,10,10);
        Form smallForm("smallForm",false,130,130);
        Form simple;
        mointorForms(simple,bigForm,smallForm);

        std::cout << "\n---Signed---" << std::endl;
        boss.signForm(simple);
        mustafa.signForm(simple);
        anonymous.signForm(simple);

        std::cout << "\n---Signed-V2---" << std::endl;
        boss.signForm(smallForm);
        mustafa.signForm(smallForm);
        anonymous.signForm(smallForm);
        
        std::cout << "\n---Signed-V3---" << std::endl;
        boss.signForm(bigForm);
        mustafa.signForm(bigForm);
        anonymous.signForm(bigForm);

        mointorForms(simple,bigForm,smallForm);
        std::cout << "\n---Error---" << std::endl;
        Form errorForm("errorForm",false,151,151);
        Form errorForm2("errorForm",false,-1,-1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}