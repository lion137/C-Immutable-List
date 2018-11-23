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
ImmutableList<T> * cons(T elem, ImmutableList<T> * list){
	return new List<T>(elem, list);
	}

/*
 * create list from any array
 */
template <class T>
ImmutableList<T> * List_init(T a [], int size){
	ImmutableList<T> * lst = new Nil<T>();
	for (T i = size - 1; i >= 0; i--)
		lst = cons(a[i], lst);
	return lst;
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

/*
 * reverse list
 */
template <class T>
ImmutableList<T> * reverse(ImmutableList<T> * list){
	return _reverse(list, new Nil<T>());
}

/*
 * reverse list helper
 */
template <class T>
ImmutableList<T> * _reverse(ImmutableList<T> * lst1, ImmutableList<T> * lst2){
	 if (lst1->is_empty())
		return lst2;
	 else
		return _reverse(lst1->tail(), cons(lst1->head(), lst2));
}
 
#endif
