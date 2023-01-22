#include "Contact.h"
#include <string>

using std::string;

Contact::Contact() {
    this->setNumberphone("NO DATA");
    this->setAdress("NO DATA");
    this->setSurname("NO DATA");
}

Contact::Contact(std::string numberphone, std::string adress, std::string surname) {
    this->setNumberphone(numberphone);
    this->setAdress(adress);
    this->setSurname(surname);
}

void Contact::setNumberphone(string numberphone) {
    this->numberphone = numberphone;
}

void Contact::setAdress(std::string adress) {
    this->adress = adress;
}

void Contact::setSurname(std::string surname) {
    this->surname = surname;
}

string Contact::getNumberphone() const {
    return numberphone;
}

string Contact::getAdress() const {
    return adress;
}

string Contact::getSurname() const {
    return surname;
}

