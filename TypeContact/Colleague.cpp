#include "Colleague.h"

Colleague::Colleague() 
    : Contact(numberphone, adress, surname)  { 
    setOrganization("NO DATA");
    setFacts("NO DATA");
}

Colleague::Colleague(string numberphone, string adress, string surname, string Organization, string facts) 
    : Contact(numberphone, adress, surname)  {
    setOrganization(Organization);
    setFacts(facts);
}

string Colleague::getFacts() const {
    return facts;
}

string Colleague::getOrganization() const {
    return Organization;
}

void Colleague::setFacts(string facts) {
    this->facts = facts;
}

void Colleague::setOrganization(string Organization) {
    this->Organization = Organization;
}

string Colleague::show() const {
    string resualt;

    resualt += "Surname: " + surname + "\n";
    resualt += "Numberphone: " + numberphone + "\n";
    resualt += "Adress: " + adress + "\n";
    resualt += "Organization: " + Organization + '\n';
    resualt += "Facts: " + facts + '\n'; 

    return resualt;
}

string Colleague::type() const {
    return "Colleague";
}