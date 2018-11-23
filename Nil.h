// Nil header

#ifndef NIL_H
#define NIL_H

#include "list.h"
#include "ImmutableList.h"

/*
 * class empty list
 */



template <class T>
class Nil: public ImmutableList<T> {
		public:
		~Nil();
		bool is_empty() {return true;}
		int length() {return 0;}
		T head() {
			throw std::logic_error("Head of empty list!");
		}
		ImmutableList<T> * tail() {
			throw std::logic_error("Tail of empty list!");
		}
};

#endif
