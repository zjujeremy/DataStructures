#include <iostream>
#include "graph.h"

using namespace std;

int main(){
	graph *gra = new graph(11);
	vertex* v1 = new vertex('A');
	vertex* v2 = new vertex('B');
	vertex* v3 = new vertex('C');
	vertex* v4 = new vertex('D');
	vertex* v5 = new vertex('E');
	vertex* v6 = new vertex('F');
	vertex* v7 = new vertex('G');
	vertex* v8 = new vertex('H');
	vertex* v9 = new vertex('I');
	vertex* v10 = new vertex('J');
	vertex* v11 = new vertex('K');

	gra->addVertex(*v1);
	gra->addVertex(*v2);
	gra->addVertex(*v3);
	gra->addVertex(*v4);
	gra->addVertex(*v5);
	gra->addVertex(*v6);
	gra->addVertex(*v7);
	gra->addVertex(*v8);
	gra->addVertex(*v9);
	gra->addVertex(*v10);
	gra->addVertex(*v11);

	gra->addEdge(0, 1, 1);
	gra->addEdge(1, 3, 1);
	gra->addEdge(3, 10, 1);
	gra->addEdge(1, 2, 1);
	gra->addEdge(2, 3, 1);
	gra->addEdge(0, 4, 1);
	gra->addEdge(4, 5, 1);
	gra->addEdge(5, 6, 1);
	gra->addEdge(5, 7, 1);
	gra->addEdge(7, 8, 1);
	gra->addEdge(7, 9, 1);
	gra->addEdge(8, 9, 1);

	gra->printAdjacencyMatrix();
	gra->DepthFirstSearch(0);
	gra->initVertexArray();
	gra->BreadthFirstSearch(0);

	return 0;
}