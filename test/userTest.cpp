//
// Created by Edoardo Canti on 30/01/24.
//
#include "gtest/gtest.h"
#include "../SystemRegister.h"
#include "../User.h"
#include <algorithm>


// username attribute getter test
TEST(User, usernameTest){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    ASSERT_EQ(alice->getUsername(), "alice");
}

// searching in contacts for a contact that was not added (expected false)
TEST(User, findUnknownContact){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    bool found = alice->findContact(bob);
    ASSERT_FALSE(found);
}

// searching in contacts for a contact that was added (expected true)
TEST(User, findKnownContact){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);
    bool found = alice->findContact(bob);
    ASSERT_TRUE(found);
}

// testing if a contact was removed
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

// searching in user_register if there is an unexisting chat (expected false)
TEST(User, findUnexistingChat){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    User* bob = new User("bob", sr);

    alice->addContact(bob);

    bool chatFound = alice->findChat(bob);
    ASSERT_FALSE(chatFound);
}

// searching in user_register for a created chat (expected true)
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