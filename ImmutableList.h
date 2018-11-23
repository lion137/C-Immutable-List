// Immutable List header

#ifndef IMMUTABLE_LIST_H
#define IMMUTABLE_LIST_H

/*
 * Abstract class
 */ 
template <class T>
class ImmutableList {
	
	public:
	~ImmutableList() {std::cout << "base class destructor";}
	virtual bool is_empty() = 0;
	virtual T head() = 0;
	virtual ImmutableList<T> * tail() = 0; 
	virtual int length() = 0;
};

#endif
