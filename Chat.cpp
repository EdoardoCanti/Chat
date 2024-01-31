//
// Created by Edoardo Canti on 29/01/24.
//

#include "Chat.h"

int Chat::global_id = 0; // static int set to 0

Chat::Chat() {
    global_id++;
    this->id = global_id;

} // every new Chat has an incremented identfier

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

int Chat::getId(){
    return id;
}