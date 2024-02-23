//
// Created by Edoardo Canti on 29/01/24.
#ifndef LAB_PROGRAMMAZIONE_MESSAGE_H
#define LAB_PROGRAMMAZIONE_MESSAGE_H

#include <string>
#include <list>
using namespace std;
class User;

class Message {

private:
    string content;
    pair<bool, list<User* > > seen;

public:
    explicit Message(const string& content); //added explicit in order to disallow implicit coversion on string type param
    const string getContent(); //add const
    void setContent(const string& content);
    const pair<bool, list<User*> > isSeen(); //add const
    void setSeen(bool in_seen, User* usr);
};


#endif //LAB_PROGRAMMAZIONE_MESSAGE_H