//
// Created by Edoardo Canti on 29/01/24.
//

#include "SystemRegister.h"

SystemRegister::SystemRegister() {}

SystemRegister* SystemRegister::getInstance() {
    if(instance == nullptr)
        instance = new SystemRegister();
    return instance;
}

void SystemRegister::addChat(Chat *c) {
    this->chats_register.push_back(c);
}

void SystemRegister::showChats() {{
    for(auto it : chats_register)
        cout<<it->getId()<<endl;
}}