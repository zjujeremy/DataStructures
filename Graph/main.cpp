#include <iostream>
#include <fstream>
#include <cstdlib>
#include "graph.h"

using namespace std;

int main(){
	int Nv, Ne;
	ifstream in("graphRelation.dat", ios::in);
	in >> Nv >> Ne;
	graph *gra = new graph(Nv, Ne);
	edge *e = new edge[gra->maxEdge];
	for (int i = 0; i < gra->maxEdge;i++){
		in >> e[i].v1 >> e[i].v2 >> e[i].value;
	}

	for (int i = 0; i < gra->maxVertex;i++){
		vertex _v;
		in >> _v.value;
		gra->addVertex(_v);
	}
	in.close();

	for (int i = 0; i < gra->maxEdge; i++){
		gra->addEdge(e[i]);
	}
	

	/*vertex* v1 = new vertex('A');
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
	gra->addVertex(*v11);*/

	/*gra->addEdge(0, 1, 1);
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
	gra->addEdge(8, 9, 1);*/

	cout << "Adjacency Matrix: " << endl;
	gra->printAdjacencyMatrix();

	cout << "Depth First Search(DFS): " << endl;
	gra->DepthFirstSearch(0);

	gra->initVertexArray();

	cout << "Breadth First Search(BFS): " << endl;
	gra->BreadthFirstSearch(0);

	system("pause");
	return 0;
}