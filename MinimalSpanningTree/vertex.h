#ifndef VERTEX_H
#define VERTEX_H

class vertex{
public:
	vertex(char n=0){
		name = n;
		isVisited = false;
		
	}
	char name;
	bool isVisited;

	//for kruskal algorithm
};

#endif