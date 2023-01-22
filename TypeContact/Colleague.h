#pragma once
#include "../ContactClass/Contact.cpp"

class Colleague : public Contact {
public:
    string Organization;
    string facts;

private:
    Colleague();
    Colleague(string numberphone, string adress, string surname, string Organization, string facts);

    void setOrganization(string Organization);
    void setFacts(string facts);

    string getOrganization() const;
    string getFacts() const;

    virtual string show() const override;
    virtual string type() const override;
};
