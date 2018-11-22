// list functions
#ifndef LIST_FUNCTIONS_CPP
#define LIST_FUNCTIONS_CPP

#include "list.h"
#include "Nil.h"
#include "ImmutableList.h"

/*
 * cons elem to the list, returns pointer to the new list
 */ 
template <class T>
List<T> * cons(T elem, ImmutableList<T> * list){
	return new List<T>(elem, list);
	}



#endif
