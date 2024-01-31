//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../SystemRegister.h"
#include "../User.h"

// Username attribute getter test
TEST(User, usernameTest){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    ASSERT_EQ(alice->getUsername(), "alice");
}

// Searching in contacts for a contact that was not added (expected false)
TEST(User, findUnknownContact){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    bool found = alice->findContact(bob);
    ASSERT_FALSE(found);
}

// Searching in contacts for a contact that was added (expected true)
TEST(User, findKnownContact){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);
    bool found = alice->findContact(bob);
    ASSERT_TRUE(found);
}

// Testing if a contact was removed
TEST(User, deleteContact){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();
    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);

    bool found = alice->findContact(bob);
    ASSERT_TRUE(found);

    alice->removeContact(bob);
    found = alice->findContact(bob);
    ASSERT_FALSE(found);
}

// Searching in user_register if there is an unexisting chat (expected false)
TEST(User, findUnexistingChat){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);

    bool chatFound = alice->findChat(bob);
    ASSERT_FALSE(chatFound);
}

// Searching in user_register for a created chat (expected true)
TEST(User, findExistingChat){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);
    alice->startChat(bob);

    bool chatFound = alice->findChat(bob);
    ASSERT_TRUE(chatFound);
}

// Checking if a user that receives a request to chat, after accepting chat adds to its contacts
// the sender contact (expected True)
TEST(User, receiverAddContacts){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);

    bool found = bob->findContact(alice);
    ASSERT_FALSE(found);

    //inside startChat bob accepts the chat, by doing this should add its contacts with alice
    alice->startChat(bob);
    found = bob->findContact(alice);
    ASSERT_TRUE(found);
}

// After starting a chat, sender user_register will contain the receiver user
TEST(User, findChatSenderRegiter){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);
    alice->startChat(bob);
    bool chatFound = alice->findChat(bob);
    ASSERT_TRUE(chatFound);
}

// After accepting a chat, receiver user_register will contain the sender user
TEST(User, findChatReceiverRegiter){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);
    alice->startChat(bob);
    bool chatFound = bob->findChat(alice);
    ASSERT_TRUE(chatFound);
}