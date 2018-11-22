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

/*
 * nth element
 */
template <class T>
T nth (int n, ImmutableList<T> * list){
	if (list->is_empty())
		throw std::out_of_range("nth: Out of Range");
	if (n == 0)
		return list->head();
	else
		return nth(n - 1, list->tail());
}

/*
 * to String
 */
template <class T>
std::ostream& operator<<(std::ostream &strm,  ImmutableList<T> * list) {
	std::string str =  "[";
	for (int i = 0; i < list->length(); i++)
		str = str + " " + std::to_string(nth(i, list));
	str += "]";
	return strm << str;
} 

#endif
