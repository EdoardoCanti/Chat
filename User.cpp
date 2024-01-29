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