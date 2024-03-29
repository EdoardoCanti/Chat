//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_SYSTEMREGISTER_H
#define LAB_PROGRAMMAZIONE_SYSTEMREGISTER_H

#include "Chat.h"
#include <iostream>
#include "User.h"

using namespace std;

class SystemRegister {

    private:
        SystemRegister();
        static SystemRegister* instance;
        list<shared_ptr<Chat> > chats_register;

    public:
        static SystemRegister* getInstance();
        void addChat(shared_ptr<Chat> c);
        void showChats() const; // changed to const member function
        void addChatMember(shared_ptr<Chat>  c, User *usr);
        int getChatsNumber() const; // changed to const member function
        void clear(); // Delete all elements in chats_register
};


#endif //LAB_PROGRAMMAZIONE_SYSTEMREGISTER_H
