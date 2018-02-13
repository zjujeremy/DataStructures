#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
class graph{
public:
	graph(int _nv, int _ne){
		maxVertex = _nv;
		maxEdge = _ne;
		nds = new vertex[maxVertex];
		preNum = 0;
	}

	void addVertex(const vertex& _v);
	void addEdge(edge& _e1, edge& _e2);

	void initVertex();
	void DepthFirstSearch(int _i);
	void BreadthFirstSearch(int _i);

	vertex* nds;
	int maxVertex;
	int maxEdge;
	int preNum;

};


#endif