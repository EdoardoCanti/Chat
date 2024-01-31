//
// Created by Edoardo Canti on 30/01/24.
//

#include "gtest/gtest.h"
#include "../Chat.h"


TEST(Chat, chatStaticIdentifier){
    Chat* c_0 = new Chat();
    ASSERT_EQ(c_0->getId(),1);
}

TEST(Chat, multipleChatsStaticIdentifier) {
    Chat *c_0 = new Chat();
    Chat *c_1 = new Chat();
    Chat *c_2 = new Chat();
    ASSERT_EQ(c_0->getId(), 1);
    ASSERT_EQ(c_1->getId(), 2);
    ASSERT_EQ(c_2->getId(), 3);
}s