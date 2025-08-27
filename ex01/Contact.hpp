#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
    private:
        std::string name;
        std::string surName;
        std::string nickName;
        std::string phoneNumber;
        std::string Secret;
    public:
        void setName(std::string ipt);
        void setSurName(std::string ipt);
        void setNickName(std::string ipt);
        void setPhoneNumber(std::string ipt);
        void setSecret(std::string ipt);
        std::string getName();
        std::string getSurName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getSecret();

};

#endif 