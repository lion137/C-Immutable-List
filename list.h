// list header

#ifndef LIST_H
#define LIST_H

#include "Nil.h"
#include "ImmutableList.h"

/*
 * class non empty List
 */

template <class T>
class List: public ImmutableList<T> {
	
	int size = 1;
	T first;
	void * rest;
	public:
	
	List(T _first, ImmutableList<T> * _tail){
		first = _first;
		rest = _tail;
		size += _tail->length();
		
	}
	
	~List() {std::cout << "List class destructor";}
	bool is_empty() { return false; }
	
	T head(){
		return first;
	}
	
	ImmutableList<T>* tail(){
		return (List<T> *) rest;
	}
	
	int length() {return size;}
};


#endif
