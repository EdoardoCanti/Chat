//
// Created by Edoardo Canti on 29/01/24.
//

#include "User.h"

using namespace std;

User::User(string username) : username(username){ }
User::User() { }

string User::getUsername() { return username; }
void User::setUsername(string username) { this->username = username; }

string User::getContactList() {
    string contactsString = "";
    list<User *>::iterator it;
    for(it = contacts.begin(); it != contacts.end(); it++){
        contactsString += (*it) -> getUsername() + "\n";
    }
}

bool User::findContact(User *usr) {
    bool found = false;
    list<User *>::iterator it;
    for (it = contacts.begin(); it != contacts.end(); it++) {
        if ((*it)->getUsername() == usr->getUsername())
            found = true;
    }
    return found;
}

bool User::addContact(User *usr) {
    bool added = false;
    if(!(this->findContact(usr))){
        contacts.push_back(usr);
        added = true;
    }
    return added;
}

bool User::removeContact(User *usr){
    bool removed = false;
    if (this->findContact(usr)){
        contacts.remove(usr);
        removed = true;
    }
    return removed;
}

