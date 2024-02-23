//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_CHAT_H
#define LAB_PROGRAMMAZIONE_CHAT_H

#include <list>
#include "Message.h"
//include "User.h"
/*
 * Chat will be composed by a static int identifier
 * and a list of messages
 * check User.h for implementation details.
 */

class User;

class Chat {

    private:
        static int global_id;
        int id;
        list<Message*> messages;
        list<User*> members;
        int messages_counter;

    public:
        Chat();
        void addMessage(Message* msg);
        list<Message*> getMessages();
        const string showMessages(); // add const
        const int getMessagesCounter(); // add const
        const int getId();
        void addMember(User* usr);
        list<User*> getMembers();
        const int getUnseenCounter(); // add const
        const int getSeenCounter(); // add const
        static void resetGlobalId();
};


#endif //LAB_PROGRAMMAZIONE_CHAT_H
