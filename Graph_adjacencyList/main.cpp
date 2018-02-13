#include <iostream>
#include <fstream>
#include <cstdlib>
#include "graph.h"
using namespace std;

int main(){
	int nv, ne;
	ifstream infile("./graphRelation.dat", ios::in);
	infile >> nv >> ne;

	graph g(nv,ne);
	vertex *v = new vertex[g.maxVertex];
	for (int i = 0; i < g.maxVertex; i++){
		infile >> v[i].Vdata;
		g.addVertex(v[i]);
	}

	edge *e = new edge[2*g.maxEdge];
	for (int i = 0; i < g.maxEdge; i++){
		infile >> e[i].preV >> e[i].nextV >> e[i].value;
		e[2 * g.maxEdge - 1 - i].nextV = e[i].preV;
		e[2 * g.maxEdge - 1 - i].preV = e[i].nextV;
		g.addEdge(e[i], e[2*g.maxEdge-1-i]);
	}
	infile.close();

	cout << "The Depth First Search:" << endl;
	g.DepthFirstSearch(0);
	g.initVertex();
	cout << "The Breadth First Search:" << endl;
	g.BreadthFirstSearch(0);

	system("pause");
	return 0;
}