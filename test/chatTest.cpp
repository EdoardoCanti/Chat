//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../Chat.h"
#include "../SystemRegister.h"
#include "../ChatNotFoundException.h"
#include "../User.h"

class ChatTest : public ::testing::Test {
protected:
    SystemRegister* sr;
    User* usr_1;
    User* usr_2;
    User* usr_3;
    User* usr_4;

    virtual void SetUp() {
        sr = SystemRegister::getInstance();
        usr_1 = new User("usr_1", *sr);
        usr_2 = new User("usr_2", *sr);
        usr_3 = new User("usr_3", *sr);
        usr_4 = new User("usr_4", *sr);
    }

    virtual void TearDown() {
        Chat::resetGlobalId();
        delete usr_1;
        delete usr_2;
        delete usr_3;
    }
};

// Testing C'tor
TEST_F(ChatTest, chatStaticIdentifier){
    shared_ptr<Chat> c = std::make_shared<Chat>();
    ASSERT_EQ(c->getId(),1);
}

// Testing the self-incremented identifier on each chat
TEST_F(ChatTest, multipleChatsStaticIdentifier) {
    shared_ptr<Chat> c0 = std::make_shared<Chat>();
    shared_ptr<Chat> c1 = std::make_shared<Chat>();
    shared_ptr<Chat> c2 = std::make_shared<Chat>();
    ASSERT_EQ(c0->getId(), 1);
    ASSERT_EQ(c1->getId(), 2);
    ASSERT_EQ(c2->getId(), 3);
}

// Testing the number of messages in chat
TEST_F(ChatTest, messagesCounter){
    shared_ptr<Chat> c = std::make_shared<Chat>();
    sr->addChat(c);
    sr->addChatMember(c, usr_1);
    sr->addChatMember(c, usr_2);
    auto chat_id = c->getId();
    usr_1->sendMessage(chat_id, "Hello World!");
    int messages_in_chat = c->getMessagesCounter(); // Expected only one message in chat
    ASSERT_EQ(messages_in_chat, 1);
    usr_2->sendMessage(chat_id, "Hi.");
    messages_in_chat = c->getMessagesCounter(); // Expected only one message in chat
    ASSERT_EQ(messages_in_chat, 2);
}

// Testing the number of seen and unseen messages in chat
/* Explaining scenario:
 * The following Chat c, will contain 3 users.
 * A message is considered seen if and only if all different users has seen it in the chat.
 * In this implementation the User that sends the message, is instantly added has the first who saw the message.
 * In order to visualize a message a User must apply User::openChat(chat_id), that will print all messages in the chat.
 * After a user ran User::openChat his name will be added into Message::seen second attribute, which is a pair composed of a
 * boolean and a list of users
 */
TEST_F(ChatTest, seenUnseenCounter){
    shared_ptr<Chat> c = std::make_shared<Chat>();
    sr->addChat(c);
    sr->addChatMember(c, usr_1);
    sr->addChatMember(c, usr_2);
    sr->addChatMember(c, usr_3);
    auto chat_id = c->getId();
    usr_1->sendMessage(chat_id, "Hello World!");
    int unseen_messages = c->getUnseenCounter(); // Only 1 msg sent, nobody except the sender saw it, expected 1
    int seen_messages = c->getSeenCounter(); // Only 1 msg sent, nobody except the sender saw it, expected 0
    ASSERT_EQ(unseen_messages, 1);
    ASSERT_EQ(seen_messages, 0);

    usr_2->openChat(chat_id);
    unseen_messages = c->getUnseenCounter(); // 1 msg sent, two of three users saw it, so it's still marked as unseen, expected 1
    seen_messages = c->getSeenCounter(); // Expected 0
    ASSERT_EQ(unseen_messages, 1);
    ASSERT_EQ(seen_messages, 0);

    usr_3->openChat(chat_id);
    unseen_messages = c->getUnseenCounter(); // three different users saw the first message. Expected 0
    seen_messages = c->getSeenCounter(); // three different users saw the first message. Expected 1
    ASSERT_EQ(unseen_messages, 0);
    ASSERT_EQ(seen_messages, 1);

    usr_2->sendMessage(chat_id, "Hi."); // New message saw only by the sender
    usr_3->openChat(chat_id); // two users in total saw the new message
    int messagges_in_chat = c->getMessagesCounter();
    unseen_messages = c->getUnseenCounter();
    seen_messages = c->getSeenCounter();
    ASSERT_EQ(messagges_in_chat, 2); // Two messages in total
    ASSERT_EQ(unseen_messages, 1); // One seen by all three users
    ASSERT_EQ(seen_messages, 1); // One seen by only 2 users
}

TEST_F(ChatTest, getUnexistingChat){
    shared_ptr<Chat> c0 = std::make_shared<Chat>();
    shared_ptr<Chat> c1 = std::make_shared<Chat>();
    sr->addChatMember(c0, usr_1);
    ASSERT_THROW(usr_1->getChat(2), ChatNotFoundException);
}

TEST_F(ChatTest, showDifferentChats){
    shared_ptr<Chat> c1 = std::make_shared<Chat>();
    sr->addChatMember(c1, usr_1);
    sr->addChatMember(c1, usr_2);
    sr->addChatMember(c1, usr_3);
    sr->addChat(c1);

    std::shared_ptr<Chat> c2 = std::make_shared<Chat>();
    sr->addChatMember(c2, usr_2);
    sr->addChatMember(c2, usr_4);
    sr->addChat(c2);

    auto chat1_id = c1->getId();
    auto chat2_id = c2->getId();
    usr_1->sendMessage(chat1_id, "Hello World.");
    usr_2->openChat(chat1_id);
    usr_2->sendMessage(chat1_id, "Hi!");

    usr_4->sendMessage(chat2_id, "Hello from usr_4");
    usr_2->openChat(chat2_id);
    usr_2->sendMessage(chat2_id,":)");
    sr->showChats();
}