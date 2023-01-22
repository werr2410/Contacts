#include "Person.h"

Person::Person()
    : Contact() { 

}

Person::Person(string numberphone, string adress, string surname) 
    : Contact(numberphone, adress, surname) { 

}

string Person::show() const {
    string resualt;

    resualt += "Surname: " + surname + "\n";
    resualt += "Numberphone: " + numberphone + "\n";
    resualt += "Adress: " + adress + "\n";

    return resualt;
}

string Person::type() const {
    return "Person";
}
