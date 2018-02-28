#include <iostream>
#include <cstdlib>
#include <fstream>
#include "graph.h"

using namespace std;
int main(){
	ifstream in("./data.dat", ios::in);
	int nv, ne;
	in >> nv >> ne;
	graph g(nv, ne);
	for (int i = 0; i < nv; i++){
		vertex v;
		v.name = char('1' + i);
		g.arrayV[i] = v;
	}

	for (int i = 0; i < ne; i++){
		int s, e, v;
		in >> s >> e >> v;
		g.addEdge(s, e, v);
	}

	// prim algorithm below
	//g.prim(0);

	// kruskal algorithm below
	g.kruskal();

	in.close();
	system("pause");
	return 0;
}

