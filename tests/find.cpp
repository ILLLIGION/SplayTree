#include "../include/SplayTree.h"
#include "catch.hpp"

SCENARIO("pointer returned, if an element is in the tree") 
{
    GIVEN("tree of int") 
    {
        SplayTree<int> tree{1, 4, 5};
        WHEN("search") 
        {
            THEN("pointer isn't nullptr") 
            {
                REQUIRE(*(tree.search(1)) == 1);
                REQUIRE(*(tree.search(4)) == 4);
                REQUIRE(*(tree.search(5)) == 5);
            }
        }
    }
}

SCENARIO("nullptr returned, if an element isn't in the tree") 
{
    GIVEN("tree of int") 
    {
        SplayTree<int> tree{1, 4, 5};
        WHEN("search") 
        {
            THEN("pointer is nullptr") 
            {
                REQUIRE(tree.search(2) == nullptr);
                REQUIRE(tree.search(3) == nullptr);
                REQUIRE(tree.search(6) == nullptr);
            }
        }
    }
}
