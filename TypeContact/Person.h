#include "../ContactClass/Contact.cpp"

class Person : public Contact {
public:
    Person();
    Person(string numberphone, string adress, string surname);

    virtual string show() const override;
    virtual string type() const override;
};
