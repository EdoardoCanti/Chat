//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_USER_H
#define LAB_PROGRAMMAZIONE_USER_H

#include <string>
#include <list>

using namespace std;

/*
 * Every User will have its register.
 * Every entry of the register will be a tuple of User,Chat.
 * A chat with a specifi user will be allowed iff the user is in the contacts of this user.
 */
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

    // Contact handling methods
    bool findContact(User* usr);
    bool addContact(User* usr);
    bool removeContact(User* usr);
};


#endif //LAB_PROGRAMMAZIONE_USER_H
