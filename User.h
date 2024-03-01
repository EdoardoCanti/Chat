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
        const string& getUsername() const; // changed to const member function
        void setUsername(const string& username);
        const SystemRegister& getSystemRegister() const; // changed to const member function

        // Chat related methods
        void addChat(shared_ptr<Chat> c);
        bool findChat(int chatId) const; // changed to const member function
        void sendMessage(int chatId, const string& content);
        void openChat(int chatId);
        int getChatsNumber() const; // changed to const member function
        shared_ptr<Chat> getChat(int chatId) const; // changed to const member function
};


#endif //LAB_PROGRAMMAZIONE_USER_H
