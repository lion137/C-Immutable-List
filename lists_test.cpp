/*
 * tests
 */


#include <iostream>
#include <gtest/gtest.h>
#include "list.h"
#include "list_functions.cpp"
#include "list.cpp"


namespace {

	class TestList: public ::testing::Test {
		protected:
		TestList();
		~TestList();
};
	
	TEST(list_init, non_empty) {
		List<int> * int_list = new List<int>(1, new Nil<int>());
		ASSERT_EQ(int_list->length(), 1);
	}
}
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
