#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
class graph{
public:
	graph(int _maxTertex);
	~graph();

	void addVertex(const vertex &);
	void addEdge(const int row, const int col, const int value);
	
	void printAdjacencyMatrix();

	void DepthFirstSearch(int _i);
	void BreadthFirstSearch();

private:
	int maxVertex;
	int preVertex;
	vertex *vertexArray;
	int *adjacencyMaxtrix;
};




#endif