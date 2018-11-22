/*
 * tests
 */


#include <iostream>
#include <gtest/gtest.h>
#include "list.h"
#include "list_functions.cpp"
#include "list.cpp"
#include "ImmutableList.h"
#include "Nil.h"


namespace {

	class TestList: public ::testing::Test {
		public:
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
		List<int> * lst2 = new List<int>(3, new List<int>(4, new Nil<int>()));
		ASSERT_TRUE(empty_list->is_empty());
		ASSERT_EQ(empty_list->length(), 0);
		ASSERT_THROW(empty_list->head(), std::logic_error);
		ASSERT_THROW(empty_list->tail(), std::logic_error);
	}
	
	TEST(testListMethods, testList){
		List<int> * int_list = new List<int>(1, new Nil<int>());
		List<int> *lst = new List<int>(2, int_list);
		ASSERT_EQ(lst->head(), 2);
		ASSERT_EQ(lst->tail(), int_list);
		ASSERT_TRUE(! lst->is_empty());
		ASSERT_TRUE(!int_list->is_empty());
		ASSERT_THROW(int_list->tail()->head(), std::logic_error);
		ASSERT_EQ(int_list->tail()->length(), 0);
		ASSERT_EQ(int_list->head(), 1);
	}
	
	TEST(testCons, testList){
		List<int> * int_list = new List<int>(1, new Nil<int>());
		int elem = 2;
		
		ImmutableList<int> * ptr = new List<int>(10, new Nil<int>());
		ASSERT_EQ(ptr->tail()->length(), 0);
		
		ASSERT_EQ(cons(elem, ptr)->length(), 2);
		ASSERT_EQ(cons(elem, new Nil<int>())->length(), 1);
	}
}
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
