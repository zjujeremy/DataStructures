#ifndef VERTEX_H
#define VERTEX_H

#include "edge.h"
class vertex{
public:
	vertex(char _c=' '){
		Vdata = _c;
		firstEdge = NULL;
		isVisited = false;
	}
	char Vdata;
	edge* firstEdge;
	bool isVisited;
};

#endif