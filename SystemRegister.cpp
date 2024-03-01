//
// Created by Edoardo Canti on 29/01/24.
//

#include "SystemRegister.h"

SystemRegister::SystemRegister()= default;

SystemRegister* SystemRegister::instance = nullptr;

SystemRegister* SystemRegister::getInstance() {
    if(instance == nullptr)
        instance = new SystemRegister();
    return instance;
}

void SystemRegister::addChat(shared_ptr<Chat> c) {
    this->chats_register.push_back(c);
}

// const member function since doesn't change the object status
void SystemRegister::showChats() const{
    for(auto it : chats_register){
        std::cout<<"--- Content of chat: "<<it->getId()<<"---"<<std::endl;
        auto members = it->getMembers();
        std::cout<<"members: "<<std::endl;
        for(auto mem : members)
            std::cout<<"    > "<<mem->getUsername()<<std::endl;
        std::cout<<"messages info: Seen:"<<it->getSeenCounter()<<"/ Total: "<<it->getMessagesCounter()<<std::endl;
        auto messages = it->getMessages();
        for(auto msg : messages)
            std::cout<<msg->getContent()<<std::endl;
    }
}

void SystemRegister::addChatMember(shared_ptr<Chat> c, User *usr){
    c->addMember(usr);
    usr->addChat(c);
}

// const member function since doesn't change the object status
int SystemRegister::getChatsNumber() const{
    return chats_register.size();
};

void SystemRegister::clear() {
    this->chats_register.clear();
}