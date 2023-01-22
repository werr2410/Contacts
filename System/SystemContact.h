#pragma once
#include "../TypeContact/Colleague.cpp"
#include "../TypeContact/Friend.cpp"
#include "../TypeContact/Person.cpp"
#include <vector>

using std::vector;

class SystemContact {
private:
    vector<Contact*> v_contact;    

public:
    SystemContact();
    
    void addContact(Contact* contact);
    void showAllContact() const;
};
