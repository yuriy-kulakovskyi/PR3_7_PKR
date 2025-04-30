#include <gtest/gtest.h>
#include "../functions/functions.h"

// Test case for creating a node
TEST(NodeTest, CreateNode) {
    Node* node = createNode(5);
    EXPECT_EQ(node->value, 5);
    EXPECT_EQ(node->next, nullptr);
    delete node; // Clean up
}