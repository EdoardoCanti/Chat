//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_MESSAGE_H
#define LAB_PROGRAMMAZIONE_MESSAGE_H

#include <string>
#include <list>
using namespace std;
class User;

class Message {

    private:
        string content;
        pair<bool, list<User*> > seen;

    public:
        Message(string content);
        Message();
        string getContent();
        void setContent(string content);
        pair<bool, list<User*> > isSeen();
        void setSeen(bool in_seen, User* usr);
};


#endif //LAB_PROGRAMMAZIONE_MESSAGE_H
