//
// Created by Edoardo Canti on 29/01/24.
//

#include "Chat.h"

int Chat::id = 0; // static int set to 0
Chat::Chat() { this->id += 1;} // every new Chat has an incremented identfier

void Chat::addMessage(Message *msg) {
    messages.push_back(msg);
}

string Chat::showMessages() {
    string conversation = "";
    list<Message*>::iterator it;
    for(it = messages.begin(); it != messages.end(); it++)
        conversation += (*it)->getContent() + "\n";
    return conversation;
}

int Chat::getId() { return id; }