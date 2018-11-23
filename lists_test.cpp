/*
 * tests
 */


#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "list.h"
#include "list_functions.cpp"
#include "ImmutableList.h"
#include "Nil.h"


namespace {

	class TestList: public ::testing::Test {
		public:
		TestList();
		~TestList();
		
};
	
	TEST(testListConstructor, testList) {
		ImmutableList<int> * int_list = new List<int>(1, new Nil<int>());
		ASSERT_EQ(int_list->length(), 1);
		ASSERT_TRUE( ! int_list->is_empty());
	}
	
	TEST(testConstructorFromList, testList){
		long a [99]; // sakramentalne:)
		for (long i = 0; i < 99; i++)
			a[i] = 1;
		ASSERT_EQ(nth(12, List_init(a, 99L)), 1);
	}
	
	TEST(testNlConstructor, testNil){
		ImmutableList<int> * empty_list = new Nil<int>();
		ImmutableList<int> * lst2 = new List<int>(3, new List<int>(4, new Nil<int>()));
		ASSERT_TRUE(empty_list->is_empty());
		ASSERT_EQ(empty_list->length(), 0);
		ASSERT_THROW(empty_list->head(), std::logic_error);
		ASSERT_THROW(empty_list->tail(), std::logic_error);
	}
	
	TEST(testListMethods, testList){
		List<int> * int_list = new List<int>(1, new Nil<int>);
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
	
	TEST(testNth, testList){
		ImmutableList<int> * empty_list = new Nil<int>();
		ImmutableList<int> * lst2 = new List<int>(3, new List<int>(4, new Nil<int>()));
		ASSERT_EQ(nth(0, lst2), 3);
		ASSERT_EQ(nth(1, lst2), 4);
		ASSERT_THROW(nth(0, empty_list), std::out_of_range);// nth from epty
		ASSERT_THROW(nth(2, lst2), std::out_of_range); // out of range
		
	}
	TEST(testReverse, testList){
		ImmutableList<int> * empty_list = new Nil<int>();
		List<int> * lst2 = new List<int>(3, new List<int>(4, new Nil<int>()));
		std::cout << lst2;
		ASSERT_EQ(nth(0, reverse(lst2)), 4);
		ASSERT_TRUE(reverse(empty_list)->length() == 0);
	}
}
int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
