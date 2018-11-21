// list functions

#ifndef LIST_FUNCTIONS_CPP
#define LIST_FUNCTIONS_CPP

long factorial(long n){
	if (n == 0)
		return 1;
	return n * factorial(n - 1);
	}

#endif
