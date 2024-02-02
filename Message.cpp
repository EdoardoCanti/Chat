//
// Created by Edoardo Canti on 29/01/24.
//

#include "Message.h"
#include <iostream>
#include <algorithm>

Message::Message(std::string content) : content(content), seen(false,0){}

Message::Message() {}

string Message::getContent() {return content;}

void Message::setContent(std::string content) {this->content = content;}

pair<bool, list<User*>> Message::isSeen() {
    return seen;
}

void Message::setSeen(bool in_seen, User* usr) {
    seen.first = in_seen;
    if(in_seen){
        if(std::find(seen.second.begin(), seen.second.end(), usr) == seen.second.end())
            seen.second.push_back(usr);
    }
}
