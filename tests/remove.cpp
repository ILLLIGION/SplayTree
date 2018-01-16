#include "../include/SplayTree.h"
#include "catch.hpp"

SCENARIO("Element isn't found")
{
	GIVEN("Tree")
	{
		SplayTree<int> tree{10,5,15,2,1};
		WHEN("remove")
		{
			THEN("This element mustn't be found")
			{
				REQUIRE(tree.remove(2314532) == 0);
			}
		}
	}
}


SCENARIO("Element is found")
{
        GIVEN("Tree")
        {
                SplayTree<int> tree{10,5,15,2,1};
                WHEN("remove")
                {
                        THEN("This element must be found")
                        {
                                REQUIRE(tree.remove(15) == 1);
                        }
                }
        }
}


