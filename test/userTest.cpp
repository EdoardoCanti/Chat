//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../SystemRegister.h"
#include <algorithm>
#include "../User.h"


class UserTest : public ::testing::Test {
    protected:
        SystemRegister* sr;
        User* alice;


    virtual void SetUp() {
        Chat::resetGlobalId();
        sr = SystemRegister::getInstance();
        alice = new User("alice", *sr);

    }

    virtual void TearDown() {
        Chat::resetGlobalId();
        delete alice;
    }
};

// Username attribute getter test
TEST_F(UserTest, getUsernameTest){
    ASSERT_EQ(alice->getUsername(), "alice");
}

// Testing the number of chats in User::chats
TEST_F(UserTest, userChatsQuantityTest){
    shared_ptr<Chat> c1 = std::make_shared<Chat>();
    shared_ptr<Chat> c2 = std::make_shared<Chat>();
    ASSERT_EQ(alice->getChatsNumber(),0); // No chats added to alice's chats
    alice->addChat(c1);
    alice->addChat(c2);
    ASSERT_EQ(alice->getChatsNumber(),2); // Expected two chats added alice's chats
}

// Testing which chats are in User::chats
TEST_F(UserTest, userChatsQualityTest){
    shared_ptr<Chat> c1 = std::make_shared<Chat>();
    shared_ptr<Chat> c2 = std::make_shared<Chat>();
    alice->addChat(c1); // Add only chat c1 to alice's chats
    ASSERT_TRUE(alice->findChat(c1->getId()));
    ASSERT_FALSE(alice->findChat(c2->getId()));
}

