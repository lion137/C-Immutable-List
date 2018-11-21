/*
 * list.cpp
 */


#include <iostream>
#include <gtest/gtest.h>
#include "list.h"
#include "list_functions.cpp"
#include <stdexcept>


/*
 * Abstract class
 */ 
template <class T>
class ImmutableList {
	
	public:
	~ImmutableList() {std::cout << "base class destructor";}
	virtual bool is_empty() = 0;
	virtual T head() = 0;
	virtual ImmutableList * tail() = 0;
	int length() {return 0;} 
};

/*
 * class empty list
 */

template <class T>
class Nil: public ImmutableList<T> {
		public:
		~Nil();
		bool is_empty() {return true;}
		T head() {
			throw std::logic_error("Head of empty list!");
		}
		ImmutableList<T> * tail() {
			throw std::logic_error("Tail of empty list!");
		}
		
		int length() {return 0;}
};

/*
 * class non empty List
 */

template <class T>
class List: public ImmutableList<T> {
	int size;
	T first;
	ImmutableList<T> * rest;
	
	public:
	List(T _first, ImmutableList<T> * _tail){
		first = _first;
		if (_tail->is_empty())
			ImmutableList<T> * _tail = new Nil<T>();
		else
			rest = _tail;
			size = 1;
	}
	~List() {std::cout << "List class destructor";}
	bool is_empty() { return false; }
	
	T head(){
		return first;
	}
	
	ImmutableList<T>* tail(){
		return rest;
	}
	
	int length() {return this->size;}
};


