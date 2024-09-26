#ifndef NODE_HPP
#define NODE_HPP
#include "list_s.h"

struct nodeInt {
	int val;
	struct List_Structure list_linker;
};

struct nodeDouble {
	double val;
	struct List_Structure list_linker;
};

struct nodeChar {
	char val;
	struct List_Structure list_linker;
};

struct nodeString {
	char *val;
	struct List_Structure list_linker;
};


#endif // NODE_HPP
