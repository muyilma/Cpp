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
        void setName(std::string ipt){name=ipt;}
        void setSurName(std::string ipt){surName=ipt;}
        void setNickName(std::string ipt){nickName=ipt;}
        void setPhoneNumber(std::string ipt){phoneNumber=ipt;}
        void setSecret(std::string ipt){Secret=ipt;}
        std::string getName(){return name;}
        std::string getSurName(){return surName;}
        std::string getNickName(){return nickName;}
        std::string getPhoneNumber(){return phoneNumber;}
        std::string getSecret(){return Secret;}
};

#endif 