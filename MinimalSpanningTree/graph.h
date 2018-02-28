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
	void kruskal();
private:
	// for prim
	int selectMinEdgeIndex();
	// for kruskal
	int minValueEdge();
	int getVecIndex(int v);
	void mergeVector(vector<int> & v1, vector<int> v2);
public:
	int maxEdge;
	int maxVertex;
	int* linkMatrix;
	vertex* arrayV;

	//for prim algorithm
	vector<edge> edgeVec;
	int edgeCount;
	edge* edgeSelected;

	//for kruskal algorithm
	vector<edge> edgeLib;
	edge* edgeSelKruskal;
	vector<vector<int>> verVec;
};

#endif