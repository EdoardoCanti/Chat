//
// Created by Edoardo Canti on 29/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_MESSAGE_H
#define LAB_PROGRAMMAZIONE_MESSAGE_H

#include <string>
using namespace std;

class Message {

private:
    string content;
    bool seen;

public:
    Message(string content);
    Message();
    string getContent();
    void setContent(string content);

    bool isSeen() ;
    void setSeen(bool seen);
};


#endif //LAB_PROGRAMMAZIONE_MESSAGE_H
