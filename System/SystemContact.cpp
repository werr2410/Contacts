#include "SystemContact.h"

SystemContact::SystemContact() {

}

void SystemContact::addContact(Contact* contact) {
    v_contact.push_back(contact);
}

void SystemContact::showAllContact() const {
    for(int i = 0; i < v_contact.size(); i++) {
        if(v_contact[i]->type() == "Person")
            std::cout << "Person: \n";
        else if(v_contact[i]->type() == "Friend")
            std::cout << "Friend: \n";
        else 
            std::cout << "Colleague: \n";

        cout << v_contact[i]->show() << endl << endl;
    }
}