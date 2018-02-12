#include <iostream>
#include <queue>
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

void graph::initVertexArray(){
	for (int i = 0; i < maxVertex; i++){
		vertexArray[i].isVisited = false;
	}
}

void graph::DepthFirstSearch(int init){
	cout << "  " << vertexArray[init].value;
	vertexArray[init].isVisited = true;
	for (int i = 0; i < maxVertex; i++){
		if (adjacencyMaxtrix[init*maxVertex + i] != 0){
			if (vertexArray[init].isVisited == false)
				DepthFirstSearch(i);
		}
		else
			continue;
	}
}

void graph::BreadthFirstSearch(int init){
	queue<int> q;
	cout << " " << vertexArray[init].value;
	vertexArray[init].isVisited = true;
	q.push(init);
	while (!q.empty()){
		int vert = q.front();
		q.pop();
		for (int i = 0; i < maxVertex; i++){
			if (adjacencyMaxtrix[vert*maxVertex + i] != 0 && vertexArray[i].isVisited == false){
				cout << " " << vertexArray[i].value;
				vertexArray[init].isVisited = true;
				q.push(i);
			}
		}
	}
}