#ifndef EDGE_H	
#define EDGE_H


class edge{
public:
	edge(){
		nextV = -1;
		preV = -1;
		nextEdge = NULL;
		value = -1;
	}
	int nextV;
	int preV;
	edge* nextEdge;
	int value;
};



#endif