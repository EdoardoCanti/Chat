//
// Created by Edoardo Canti on 30/01/24.
//

#include "GroupChat.h"

GroupChat::GroupChat(list<User*> members){
    for(auto it:members){
        this->members.insert(it);
    }
}

void GroupChat::addMember(User *usr) {
    this->members.insert(usr);
}

const set<User *> &GroupChat::getMembers() const {
    return members;
}

