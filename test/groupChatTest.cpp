//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../GroupChat.h"
#include "../User.h"

TEST(GroupChat, groupChatSize){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);
    User* mario = new User("mario", sr);

    alice->addContact(bob);
    alice->addContact(mario);

    list<User*> users;
    users.push_back(alice);
    users.push_back(bob);
    users.push_back(mario);

    int users_size = users.size();
    GroupChat* group = alice->createGroup(users);
    ASSERT_EQ(users_size, group->getMembers().size());
}

TEST(GroupChat, groupChatMembers){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);
    User* mario = new User("mario", sr);

    alice->addContact(bob);
    alice->addContact(mario);

    list<User*> users;
    users.push_back(alice);
    users.push_back(bob);
    users.push_back(mario);
    GroupChat* group = alice->createGroup(users);
    int count = 0;
    for(auto it : group->getMembers()){
        if(it->getUsername() == alice->getUsername() ||
           it->getUsername() == bob->getUsername()  ||
           it->getUsername() == mario->getUsername())
            count++;
    }
    ASSERT_EQ(count, 3);
}
