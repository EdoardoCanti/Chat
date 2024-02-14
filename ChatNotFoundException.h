//
// Created by Edoardo Canti on 09/02/24.
//

#ifndef LAB_PROGRAMMAZIONE_CHATNOTFOUNDEXCEPTION_H
#define LAB_PROGRAMMAZIONE_CHATNOTFOUNDEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

class ChatNotFoundException : public exception {
    public:
        const char* what(){
            return "Chat not found!\n";
        }
};



#endif //LAB_PROGRAMMAZIONE_CHATNOTFOUNDEXCEPTION_H
