//
// Created by Edoardo Canti on 29/01/24.
//

#include "Message.h"

Message::Message(std::string content) : content(content), seen(false){}
Message::Message() {}

string Message::getContent() {return content;}
void Message::setContent(std::string content) {this->content = content;}

bool Message::isSeen(){
    return seen;
}

void Message::setSeen(bool seen) {
    Message::seen = seen;
}
