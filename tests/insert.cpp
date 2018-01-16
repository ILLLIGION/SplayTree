#include "../library.h"
#include "catch.hpp"

SCENARIO("if element already exists => return false")
{
    GIVEN("some tree")
    {
        SplayTree<int> tree{1, 3, 5, 7};
        WHEN("insert element")
        {
            THEN("elements can't be repeated")
            {
                REQUIRE(!tree.insert(1));
            }
        }   
    }    
}
SCENARIO("if element doesn't exist => return true")
{
    GIVEN("some tree")
    {
        SplayTree<int> tree{1, 3, 5, 7};
        WHEN("insert element")
        {
            THEN("element was inserted")
            {
                REQUIRE(tree.insert(10));
            }
        }   
    }    
}
SCENARIO("if element is inserted, it must become root")
{
    GIVEN("some tree")
    {
        SplayTree<int> tree{2,3};
	SplayTree<int> tree2{2,3,5};
        WHEN("insert element")
        {
            tree.insert(5);
            THEN("element must be in the root")
            {
                REQUIRE(tree == tree2);
            }
        }
    }   
}
