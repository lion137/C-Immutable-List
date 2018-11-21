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
	
	TEST(testListConstructor, testList) {
		List<int> * int_list = new List<int>(1, new Nil<int>());
		ASSERT_EQ(int_list->length(), 1);
		ASSERT_TRUE( ! int_list->is_empty());
	}
	
	TEST(testNlConstructor, testNil){
		Nil<int> * empty_list = new Nil<int>();
		Nil<int> lst();
		ASSERT_TRUE(empty_list->is_empty());
		ASSERT_EQ(empty_list->length(), 0);
		ASSERT_THROW(empty_list->head(), std::logic_error);
		ASSERT_THROW(empty_list->tail(), std::logic_error);
	}
	
	TEST(testListMethods, testList){
		List<int> * int_list = new List<int>(1, new Nil<int>());
		ASSERT_EQ(int_list->head(), 1);
		ASSERT_EQ(int_list->tail()->length(), 0);
	}
}
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
