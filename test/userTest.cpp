//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../SystemRegister.h"
#include <algorithm>
#include "../User.h"

// Username attribute getter test
TEST(User, getUsernameTest){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();
    User* alice = new User("alice", sr);
    ASSERT_EQ(alice->getUsername(), "alice");
}

// Default C'tor username attribute getter setter test
TEST(User, setUsernameTest){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();
    User* alice = new User();
    alice->setUsername("alice");
    ASSERT_EQ(alice->getUsername(), "alice");
}

// Default C'tor SystemRegister attribute getter setter test
TEST(User, setSystemRegisterTest){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();
    User* alice = new User();
    alice->setUsername("alice");
    alice->setSystemRegister(sr);
    ASSERT_EQ(alice->getSystemRegister(), sr);
}

// number of chats in chats attribute test
TEST(User, userChatsQuantityTest){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();
    User* alice = new User("alice", sr);
    Chat* c1 = new Chat();
    Chat* c2 = new Chat();
    ASSERT_EQ(alice->getChatsNumber(),0);
    alice->addChat(c1);
    alice->addChat(c2);
    ASSERT_EQ(alice->getChatsNumber(),2);
}

// which chats in chats attribute are collected
TEST(User, userChatsQualityTest){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();
    User* alice = new User("alice", sr);
    Chat* c1 = new Chat();
    Chat* c2 = new Chat();
    alice->addChat(c1);
    list<Chat*> alices_chats = alice->getChats();
    ASSERT_TRUE(std::find(alices_chats.begin(), alices_chats.end(), c1) != alices_chats.end());
    ASSERT_TRUE(std::find(alices_chats.begin(), alices_chats.end(), c2) == alices_chats.end());
}

