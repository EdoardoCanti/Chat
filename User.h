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
    list<shared_ptr<Chat> > chats;
    SystemRegister* sr; //reference to global SystemRegister

public:
    // C'tors
    User(string username, SystemRegister* sr);
    User();

    // Getters and Setters
    string getUsername();
    void setUsername(string username);
    SystemRegister* getSystemRegister();
    void setSystemRegister(SystemRegister* sr);

    // Chat related methods
    void addChat(shared_ptr<Chat> c);
    bool findChat(shared_ptr<Chat> c);
    void sendMessage(shared_ptr<Chat> c, string content);
    void openChat(shared_ptr<Chat> c);
    int getChatsNumber();
    list<shared_ptr<Chat> > getChats();

};


#endif //LAB_PROGRAMMAZIONE_USER_H
