#pragma once
#include <string>

using std::string;

class Contact {
protected:
    string numberphone;
    string adress;
    string surname;

public:
    Contact();
    Contact(string numberphone, string adress, string surname);

    void setNumberphone(string numberphone);
    void setAdress(string adress);
    void setSurname(string surname);

    string getNumberphone() const;
    string getAdress() const;
    string getSurname() const;

    virtual string show() const = 0;
    virtual string type() const = 0;

};
