#ifndef GRAPH_H
#define GRAPH_H

#include "edge.h"
#include "vertex.h"
class graph{
public:
	graph(int _maxVertex=0, int _maxEdge=0);
	~graph();

	void addVertex(const vertex &);
	void addEdge(const edge &);
	
	void printAdjacencyMatrix();
	void initVertexArray();

	void DepthFirstSearch(int init);
	void BreadthFirstSearch(int init);

	int maxVertex;
	int maxEdge;
	int preVertex;
	vertex *vertexArray;
	int *adjacencyMaxtrix;
};

#endif