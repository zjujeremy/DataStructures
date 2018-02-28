#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include <vector>
#include "edge.h"
using namespace std;
class graph{
public:
	graph(int nv, int ne);
	~graph();
	void addEdge(int s, int e, int v);

	void prim(int startVertexIndex);
private:
	int selectMinEdgeIndex();
public:
	int maxEdge;
	int maxVertex;
	int* linkMatrix;
	vertex* arrayV;
	vector<edge> edgeVec;
	int edgeCount;
	edge* edgeSelected;
};



#endif