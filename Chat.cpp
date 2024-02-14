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

list<Message*> Chat::getMessages(){
    return messages;
}

string Chat::showMessages() {
    string conversation = "";
    list<Message*>::iterator it;
    for(it = messages.begin(); it != messages.end(); it++)
        conversation += (*it)->getContent() + "\n";
    return conversation;
}

int Chat::getMessagesCounter() {
    return messages_counter;
}

int Chat::getId(){
    return id;
}

void Chat::addMember(User* usr){
    members.push_back(usr);
}

list<User*> Chat::getMembers(){
    return members;
}

int Chat::getSeenCounter() {
    int seen_counter = 0;
    for (auto it: messages) {
        if (it->isSeen().first && it->isSeen().second.size() == getMembers().size())
            seen_counter += 1;
    }
    return seen_counter;
}

int Chat::getUnseenCounter(){
    int seen_counter = getSeenCounter();
    return getMessagesCounter() - seen_counter;
}

