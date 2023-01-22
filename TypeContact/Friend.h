#pragma once
#include "../ContactClass/Contact.cpp"
#include "../OtherClass/Date/Date.cpp"

class Friend : public Contact {
private:
    Date Birthday;

public:
    Friend();
    Friend(string numberphone, string adress, string surname, Date birthday);

    void setBirthday(Date Birthday);
    Date getBirthday() const;

    virtual string show() const override;
    virtual string type() const override;
};
