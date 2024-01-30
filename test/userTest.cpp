//
// Created by Edoardo Canti on 30/01/24.
//
#include "gtest/gtest.h"
#include "../SystemRegister.h"
#include "../User.h"

TEST(User, usernameTest){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();

    User* alice = new User("alice", sr);
    ASSERT_EQ(alice->getUsername(), "alice");
}