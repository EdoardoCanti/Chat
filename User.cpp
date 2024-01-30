//
// Created by Edoardo Canti on 29/01/24.
//

#include "User.h"

using namespace std;

User::User(string username, SystemRegister* sr) : username(username), sr(sr){ }
User::User() { }

string User::getUsername() { return username; }
void User::setUsername(string username) { this->username = username; }

string User::getContactList() {
    string contactsString = "";
    list<User *>::iterator it;
    for(it = contacts.begin(); it != contacts.end(); it++){
        contactsString += (*it) -> getUsername() + "\n";
    }
    return contactsString;
}

bool User::findContact(User *usr) {
    bool found = false;
    list<User *>::iterator it;
    for (it = contacts.begin(); it != contacts.end(); it++) {
        if ((*it)->getUsername() == usr->getUsername())
            found = true;
    }
    return found;
}

bool User::addContact(User *usr) {
    bool added = false;
    if(!(this->findContact(usr))){
        contacts.push_back(usr);
        added = true;
    }
    return added;
}

bool User::removeContact(User *usr){
    bool removed = false;
    if (this->findContact(usr)){
        contacts.remove(usr);
        removed = true;
    }
    return removed;
}

bool User::findChat(User *usr) {
    bool found = false;
    for(auto it : user_register){
        if(it.first == usr)
            found = true;
    }
    return found;
}

Chat* User::returnChat(User *usr) {
    for(auto it : user_register){
        if(it.first == usr)
            return it.second;
    }
    return nullptr;
}

void User::acceptChat(User* usr, Chat* c){
    pair<User*, Chat*> pair(usr, c);
    user_register.push_front(pair);
    this->addContact(usr);
}

Chat* User::startChat(User *usr) {
    Chat* c = nullptr;
    if(findContact(usr)){
        if(!findChat(usr)){
            c = new Chat();
            pair<User*, Chat*> pair(usr, c);
            user_register.push_front(pair);
            //the other user needs to accept the chat, in order to have a reference to the same object
            usr->acceptChat(this, c);
            this->sr->addChat(c);
        }else{
            c = returnChat(usr);
        }
        return c;
    }else{
        this->addContact(usr);
        return c;
    }
}

GroupChat* User::createGroup(list<User*> members){
    GroupChat* c = nullptr;
    for(auto it : members){
        if(findContact(it)){
            c = new GroupChat(members);
            c->addMember(this);
        }
    }
    return c;
}

void User::sendMessage(Chat *c, std::string content) {
    string complete_content = "";
    string meta_data = this->getUsername();
    complete_content = meta_data+": "+content;
    Message* msg = new Message(complete_content);
    c->addMessage(msg);
}

void User::getRegister() {
    std::cout<<"register of: "<<this->getUsername()<<std::endl;
    for(auto it : user_register){
        std::cout<<"user: "<<it.first->getUsername()<<std::endl;
        std::cout<<"chat: "<<it.second->showMessages()<<std::endl;
        std::cout<<"----"<<std::endl;
    }
}
