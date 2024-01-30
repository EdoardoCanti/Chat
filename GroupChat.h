//
// Created by Edoardo Canti on 30/01/24.
//

#ifndef LAB_PROGRAMMAZIONE_GROUPCHAT_H
#define LAB_PROGRAMMAZIONE_GROUPCHAT_H

#include "Chat.h"
//#include "User.h"
#include <set>
using namespace std;

class User;

class GroupChat : public Chat{

private:
    set<User*> members;

public:
    GroupChat(list<User*> members);
    void addMember(User* usr);
    const set<User *> &getMembers() const;
};


#endif //LAB_PROGRAMMAZIONE_GROUPCHAT_H
