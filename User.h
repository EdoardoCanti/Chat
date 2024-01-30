//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_USER_H
#define LAB_PROGRAMMAZIONE_USER_H

#include <string>
#include <list>
#include "Chat.h"
#include "SystemRegister.h"
#include "GroupChat.h"

//class GroupChat;

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
    // List of pairs of type <User, Chat> in order to easily retrieve the chat with a specific user.
    list<pair<User*, Chat*>> user_register;
    SystemRegister* sr; //reference to global SystemRegister

public:
    // C'tors
    User(string username, SystemRegister* sr);
    User();

    // Getters and Setters
    string getUsername();
    void setUsername(string username);
    string getContactList();

    // Contact handling methods
    bool findContact(User* usr);
    bool addContact(User* usr);
    bool removeContact(User* usr);


    bool findChat(User* usr);
    Chat* returnChat(User* usr);
    void acceptChat(User* usr, Chat* c);
    Chat* startChat(User* usr);
    void sendMessage(Chat* c, string content);

    void getRegister();

    GroupChat* createGroup(list<User*> members);
};


#endif //LAB_PROGRAMMAZIONE_USER_H
