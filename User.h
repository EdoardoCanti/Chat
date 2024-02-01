//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_USER_H
#define LAB_PROGRAMMAZIONE_USER_H

#include <string>
#include <list>
#include "Chat.h"
//#include "SystemRegister.h"
//#include "GroupChat.h"

class SystemRegister;
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
    list<Chat*> chats;
    // List of pairs of type <User, Chat> in order to easily retrieve the chat with a specific user.
    //list<pair<User*, Chat*> > user_register;
    SystemRegister* sr; //reference to global SystemRegister

public:
    // C'tors
    User(string username, SystemRegister* sr);
    User();

    // Getters and Setters
    string getUsername();
    void setUsername(string username);
    list<User*> getContacts();
    void addChat(Chat* c);
    list<Chat*> getChats();
    string getContactList();
    bool findChat(Chat *c);
    void sendMessage(Chat* c, string content);
    void openChat(Chat* c);

};


#endif //LAB_PROGRAMMAZIONE_USER_H
