//
// Created by Edoardo Canti on 29/01/24.
//

#include "Chat.h"
#include <iostream>

int Chat::global_id = 0; // static int set to 0

void Chat::resetGlobalId() { global_id = 0;} // static method in order to reset global id for tests tearDown

Chat::Chat() {
    global_id++;
    this->id = global_id;
    this->messages_counter = 0;
} // every new Chat has an incremented identifier


void Chat::addMessage(Message* msg) {
    messages.push_back(msg);
    messages_counter += 1;
}

// const member function since does not changes the object status
list<Message*> Chat::getMessages() const{
    return messages;
}

// const member function since does not changes the object status
string Chat::showMessages() const{
    string conversation = "";
    for(auto it = messages.begin(); it != messages.end(); it++)
        conversation += (*it)->getContent() + "\n";
    return conversation;
}

// const member function since does not changes the object status
int Chat::getMessagesCounter() const{
    return messages_counter;
}

// const member function since does not changes the object status
const int Chat::getId() const{
    return id;
}

void Chat::addMember(User* usr){
    members.push_back(usr);
}

// const member function since does not changes the object status
list<User*> Chat::getMembers() const{
    return members;
}

// const member function since does not changes the object status
int Chat::getUnseenCounter() const{
    int seen_counter = getSeenCounter();
    return getMessagesCounter() - seen_counter;
}

// const member function since does not changes the object status
int Chat::getSeenCounter() const{
    int seen_counter = 0;
    for (auto it: messages) {
        if (it->isSeen().first && it->isSeen().second.size() == getMembers().size())
            seen_counter += 1;
    }
    return seen_counter;
}



