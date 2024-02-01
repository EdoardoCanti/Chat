//
// Created by Edoardo Canti on 29/01/24.
//

#include "User.h"
#include <iostream>

using namespace std;

User::User(string username, SystemRegister* sr) : username(username), sr(sr){ }

User::User() { }

string User::getUsername() { return username; }

void User::setUsername(string username) { this->username = username; }

void User::addChat(Chat *c) {
    chats.push_back(c);
}

bool User::findChat(Chat* c) {
    bool found = false;
    for(auto it : chats){
        if(it == c)
            found = true;
    }
    return found;
}

void User::sendMessage(Chat* c, string content){
    string complete_content = "";
    string meta_data = this->getUsername();
    complete_content = meta_data+": "+content;
    Message* msg = new Message(complete_content);
    if(findChat(c)){
        c->addMessage(msg);
        msg->setSeen(true, this);
    }
}

void User::openChat(Chat *c) {
    if(findChat(c)){
        for(auto it : c->getMessages()){
            std::cout<<it->getContent()<<std::endl;
            if(it->isSeen().first && it->isSeen().second.size() < c->getMembers().size()){
                it->setSeen(true, this);
            }
        }
    }
}



