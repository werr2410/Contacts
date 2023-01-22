#include "Friend.h"

Friend::Friend()
    : Contact() {
    setBirthday(Date());
}

Friend::Friend(string numberphone, string adress, string surname, Date birthday) 
    : Contact(numberphone, adress, surname)  {
    setBirthday(birthday);
}

Date Friend::getBirthday() const {
    return this->Birthday;
}

void Friend::setBirthday(Date Birthday) {
    this->Birthday = Birthday;
}

string Friend::show() const {
    string resualt;

    resualt += "Surname: " + surname + "\n";
    resualt += "Numberphone: " + numberphone + "\n";
    resualt += "Adress: " + adress + "\n";
    resualt += "BirthDay: " + Birthday.getYear() + '.' + Birthday.getMonth() + '.' + Birthday.getDay() + '\n';

    return resualt;
}

string Friend::type() const {
    return "Friend";
}