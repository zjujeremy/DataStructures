#include <iostream>
#include "graph.h"
using namespace std;

graph::graph(int _maxTertex){
	maxVertex = _maxTertex;
	preVertex = 0;
	vertexArray = new vertex(11);
	adjacencyMaxtrix = new int(maxVertex*maxVertex);
	for (int i = 0; i < maxVertex*maxVertex; i++)
		adjacencyMaxtrix[i] = 0;
}

graph::~graph(){
	delete[] vertexArray;
	delete[] adjacencyMaxtrix;
}

void graph::addVertex(const vertex & _v){
	if (preVertex < maxVertex){
		vertexArray[preVertex] = _v;
		preVertex++;
	}
	else
		cout << "out of bound" << endl;
}

void graph::addEdge(const int row, const int col, int _value){
	adjacencyMaxtrix[row*maxVertex + col] = _value;
	adjacencyMaxtrix[col*maxVertex + row] = _value;
}

void graph::printAdjacencyMatrix(){
	for (int i = 0; i < preVertex; i++)
		cout << "  " << vertexArray[i].value;
	cout << endl;
	for (int i = 0; i < maxVertex; i++){
		cout << vertexArray[i].value;
		for (int j = 0; j < maxVertex; j++){
			cout << "  " << adjacencyMaxtrix[i*maxVertex + j];
			if (j == maxVertex - 1)
				cout << endl;
		}
	}
}

void graph::DepthFirstSearch(int _i){
	cout << "  " << vertexArray[_i].value;
	vertexArray[_i].isVisited = true;
	for (int i = 0; i < maxVertex; i++){
		if (adjacencyMaxtrix[_i*maxVertex+i] != 0){
			if (vertexArray[_i].isVisited == false)
				DepthFirstSearch(i);
		}
		else
			continue;
	}
}

void graph::BreadthFirstSearch(){

}