//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../Message.h"

// Testing content getter
TEST(Message, contentTest){
    string testString = "Hello World";
    Message* msg = new Message(testString);
    ASSERT_EQ(msg->getContent(), testString);
}

// Testing content setter
TEST(Message, setContent){
    string stringToSet = "A placeholder testing content.";
    Message* msg = new Message("HelloWorld!");
    msg->setContent(stringToSet);
    ASSERT_EQ(stringToSet, msg->getContent());
}