#ifndef EDGE_H
#define EDGE_H

class edge{
public:
	edge(){
		vertexA = -1;
		vertexB = -1;
		value = -1;
		isSelected = false;
	}
	int vertexA, vertexB;
	int value;
	bool isSelected;
};


#endif