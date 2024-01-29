//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_CHAT_H
#define LAB_PROGRAMMAZIONE_CHAT_H

#include <list>
#include "Message.h"
/*
 * Chat will be composed by a static int identifier
 * and a list of messages
 * check User.h for implementation details.
 */
class Chat {

private:
    static int id;
    list<Message*> messages;

public:
    Chat();
    void addMessage(Message* msg);
    string showMessages();
    static int getId();

};


#endif //LAB_PROGRAMMAZIONE_CHAT_H
