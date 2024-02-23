//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_USER_H
#define LAB_PROGRAMMAZIONE_USER_H

#include <string>
#include <list>
#include "Chat.h"

class SystemRegister;
using namespace std;

class User {

    private:
        string username;
        list<shared_ptr<Chat> > chats;
        const SystemRegister& sr;

    public:
        // C'tor
        User(const string& username, const SystemRegister& sr);

        // Getters and Setters
        const string getUsername(); // add const
        void setUsername(const string& username);
        const SystemRegister& getSystemRegister();

        // Chat related methods
        void addChat(shared_ptr<Chat> c);
        bool findChat(int chatId);
        void sendMessage(int chatId, const string& content);
        void openChat(int chatId);
        const int getChatsNumber(); // add const
        const shared_ptr<Chat> getChat(int chatId); // add const
};


#endif //LAB_PROGRAMMAZIONE_USER_H
