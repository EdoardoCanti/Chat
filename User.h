//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_USER_H
#define LAB_PROGRAMMAZIONE_USER_H

#include <string>
#include <list>

using namespace std;
class User {

private:
    string username;
    list<User*> contacts;

public:
    // C'tors
    User(string username);
    User();

    // Getters and Setters
    string getUsername();
    void setUsername(string username);
    string getContactList();
};


#endif //LAB_PROGRAMMAZIONE_USER_H
