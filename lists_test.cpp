/*
 * tests
 */


#include <iostream>
#include <gtest/gtest.h>
#include "list.h"
#include "list_functions.cpp"
#include "list.cpp"


namespace {

	class TestTests: public ::testing::Test {
		protected:
		TestTests();
		~TestTests();
	};
	
	TEST(FactorialTest, HandlesZeroInput) {
			EXPECT_EQ(factorial(0), 1);
		}
	TEST(FactorialTest, NonZerpInput) {
			ASSERT_EQ(factorial(3), 6);
		}

}
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
