//
// Created by Edoardo Canti on 29/01/24.
//

#include "User.h"
#include "ChatNotFoundException.h"
#include <iostream>

using namespace std;

User::User(const string& username, const SystemRegister& sr) : username(username), sr(sr) {}

// const member function because does not change the object status.
// since username is constant also return const string ref
const string& User::getUsername() const { return username; }


void User::setUsername(const string& username) { this->username = username; }

// const member function because does not change the object status.
const SystemRegister& User::getSystemRegister() const { return sr; }

void User::addChat(shared_ptr<Chat> c) {
    chats.push_back(c);
}

bool User::findChat(int chatId) const{ // id univoco
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

// const member function since doesn't change the object status
int User::getChatsNumber() const{
    return chats.size();
}

// const member function since doesn't change the object status
shared_ptr<Chat> User::getChat(int chatId) const {
    shared_ptr<Chat> chat = nullptr;
    if (findChat(chatId)){
        for (auto it: chats)
            if (it->getId() == chatId)
                chat = it;
    }
    return chat;
}




