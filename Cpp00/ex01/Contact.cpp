#include "PhoneBook.hpp"

Contact *PhoneBook::getUser() { return user; }
void Contact::setName(std::string ipt) { name = ipt; }
void Contact::setSurName(std::string ipt) { surName = ipt; }
void Contact::setNickName(std::string ipt) { nickName = ipt; }
void Contact::setPhoneNumber(std::string ipt) { phoneNumber = ipt; }
void Contact::setSecret(std::string ipt) { Secret = ipt; }
std::string Contact::getName() { return name; }
std::string Contact::getSurName() { return surName; }
std::string Contact::getNickName() { return nickName; }
std::string Contact::getPhoneNumber() { return phoneNumber; }
std::string Contact::getSecret() { return Secret; }