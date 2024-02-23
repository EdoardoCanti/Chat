//
// Created by Edoardo Canti on 29/01/24.
//

#include "User.h"
#include "ChatNotFoundException.h"
#include <iostream>

using namespace std;

User::User(const string& username, const SystemRegister& sr) : username(username), sr(sr) {}

const string User::getUsername() { return username; }

void User::setUsername(const string& username) { this->username = username; }

const SystemRegister& User::getSystemRegister() { return sr; }

void User::addChat(shared_ptr<Chat> c) {
    chats.push_back(c);
}

bool User::findChat(int chatId) { // id univoco
    bool found = false;
    for(auto it : chats)
        if(it->getId() == chatId)
            found = true;
    if(!found)
        throw ChatNotFoundException();
    return found;
}

void User::sendMessage(int chatId, const string& content){
    string complete_content = "";
    string meta_data = this->getUsername();
    complete_content = meta_data+": "+content;
    Message* msg = new Message(complete_content);
    if(findChat(chatId)){
        auto chat = this->getChat(chatId);
        chat->addMessage(msg);
        msg->setSeen(true, this);
    }
}

void User::openChat(int chatId) {
    if(findChat(chatId)){
        auto chat = getChat(chatId);
        for(auto it : chat->getMessages()){
            std::cout<<it->getContent()<<std::endl;
            if(it->isSeen().first && it->isSeen().second.size() < chat->getMembers().size()){
                it->setSeen(true, this);
            }
        }
    }

}

const int User::getChatsNumber() {
    return chats.size();
}

const shared_ptr<Chat> User::getChat(int chatId) {
    shared_ptr<Chat> chat = nullptr;
    if (findChat(chatId)){
        for (auto it: chats)
            if (it->getId() == chatId)
                chat = it;
    }
    return chat;
}




