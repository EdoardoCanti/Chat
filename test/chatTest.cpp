//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../SystemRegister.h"
#include "../User.h"

// Testing C'tor
TEST(Chat, chatStaticIdentifier){
    shared_ptr<Chat> c_0 = std::make_shared<Chat>();
    ASSERT_EQ(c_0->getId(),1);
}

// Testing the self-incremented identifier on each chat
TEST(Chat, multipleChatsStaticIdentifier) {
    shared_ptr<Chat> c_0= std::make_shared<Chat>();
    shared_ptr<Chat> c_1 = std::make_shared<Chat>();
    shared_ptr<Chat> c_2 = std::make_shared<Chat>();
    ASSERT_EQ(c_0->getId(), 1);
    ASSERT_EQ(c_1->getId(), 2);
    ASSERT_EQ(c_2->getId(), 3);
}

// Testing the number of messages in chat
TEST(Chat, messagesCounter){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();
    User* usr_1 = new User("usr_1", sr);
    User* usr_2 = new User("usr_2", sr);
    shared_ptr<Chat> c = std::make_shared<Chat>();
    sr->addChat(c);
    sr->addChatMember(c, usr_1);
    sr->addChatMember(c, usr_2);

    usr_1->sendMessage(c, "Hello World!");
    int messages_in_chat = c->getMessagesCounter(); // Expected only one message in chat
    ASSERT_EQ(messages_in_chat, 1);

    usr_2->sendMessage(c, "Hi.");
    messages_in_chat = c->getMessagesCounter(); // Expected only one message in chat
    ASSERT_EQ(messages_in_chat, 2);
}

// Testing the number of seen and unseen messages in chat
TEST(Chat, seenUnseenCounter){
    SystemRegister* sr;
    sr = SystemRegister::getInstance();
    User* usr_1 = new User("usr_1", sr);
    User* usr_2 = new User("usr_2", sr);
    User* usr_3 = new User("usr_3", sr);
    //Chat* c = new Chat();
    std::shared_ptr<Chat> c = std::make_shared<Chat>();
    sr->addChat(c);
    sr->addChatMember(c, usr_1);
    sr->addChatMember(c, usr_2);
    sr->addChatMember(c, usr_3);

    usr_1->sendMessage(c, "Hello World!");
    int unseen_messages = c->getUnseenCounter(); // Only 1 msg sent, nobody except the sender saw it, expected 1
    int seen_messages = c->getSeenCounter(); // Only 1 msg sent, nobody except the sender saw it, expected 0
    ASSERT_EQ(unseen_messages, 1);
    ASSERT_EQ(seen_messages, 0);

    usr_2->openChat(c);
    unseen_messages = c->getUnseenCounter(); // 1 msg sent, two of three users saw it, so it's still marked as unseen, expected 1
    seen_messages = c->getSeenCounter(); // Expected 0
    ASSERT_EQ(unseen_messages, 1);
    ASSERT_EQ(seen_messages, 0);

    usr_3->openChat(c);
    unseen_messages = c->getUnseenCounter(); // three different users saw the first message. Expected 0
    seen_messages = c->getSeenCounter(); // three different users saw the first message. Expected 1
    ASSERT_EQ(unseen_messages, 0);
    ASSERT_EQ(seen_messages, 1);

    usr_2->sendMessage(c, "Hi."); // New message saw only by the sender
    usr_3->openChat(c); // two users in total saw the new message
    int messagges_in_chat = c->getMessagesCounter();
    unseen_messages = c->getUnseenCounter();
    seen_messages = c->getSeenCounter();
    ASSERT_EQ(messagges_in_chat, 2); // Two messages in total
    ASSERT_EQ(unseen_messages, 1); // One seen by all three users
    ASSERT_EQ(seen_messages, 1); // One seen by only 2 users
}