//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_SYSTEMREGISTER_H
#define LAB_PROGRAMMAZIONE_SYSTEMREGISTER_H

#include "Chat.h"
#include <iostream>

using namespace std;

class SystemRegister {
private:
    SystemRegister();
    static SystemRegister* instance;
    list<Chat*> chats_register;

public:
    static SystemRegister* getInstance();
    void addChat(Chat* c);
    void showChats();
};


#endif //LAB_PROGRAMMAZIONE_SYSTEMREGISTER_H
