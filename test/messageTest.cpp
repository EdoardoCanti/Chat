//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../Message.h"

TEST(Message, contentTest){
    string testString = "Hello World";
    Message* msg = new Message(testString);
    auto content = msg->getContent();
    ASSERT_EQ(testString, content);
}

TEST(Message, setContent){
    string stringToSet = "A placeholder testing content.";
    Message* msg = new Message("HelloWorld!");
    msg->setContent(stringToSet);
    ASSERT_EQ(stringToSet, msg->getContent());
}

TEST(Message, unseenMessage){
    string content = "Hello World";
    Message* msg = new Message(content);
    ASSERT_FALSE(msg->isSeen());
}

TEST(Message, seenMessage){
    string content = "Hello World";
    Message* msg = new Message(content);
    msg->setSeen(true);
    ASSERT_TRUE(msg->isSeen());
}