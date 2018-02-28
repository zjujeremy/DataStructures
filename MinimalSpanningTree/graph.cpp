#include "graph.h"
#include <cstring>
#include <iostream>

using namespace std;

graph::graph(int nv, int ne){
	maxVertex = nv;
	maxEdge = ne;
	linkMatrix = new int[maxVertex*maxVertex];
	memset(linkMatrix, 0, maxVertex*maxVertex*sizeof(int));
	arrayV = new vertex[maxVertex];
	edgeVec.clear();
	edgeCount = 0;
	edgeSelected = new edge[maxVertex - 1];
}

graph::~graph(){
	delete[] linkMatrix;
	delete[] arrayV;
	delete[] edgeSelected;
}

void graph::addEdge(int s, int e, int v){
	linkMatrix[s*maxVertex + e] = v;
	linkMatrix[e*maxVertex + s] = v;
}

void graph::prim(int startVertexIndex){
	int ind;
	arrayV[startVertexIndex].isVisited = true;
	ind = startVertexIndex;
	while (edgeCount < maxVertex - 1){
		for (int i = 0; i < maxVertex; i++){
			if (linkMatrix[ind*maxVertex + i] != 0 && arrayV[i].isVisited == false){
				edge e;
				e.vertexA = ind;
				e.vertexB = i;
				e.value = linkMatrix[ind*maxVertex + i];
				edgeVec.push_back(e);
			}
		}
		int indexEdge = selectMinEdgeIndex();
		edgeVec[indexEdge].isSelected = true;
		cout << arrayV[edgeVec[indexEdge].vertexA].name << "-->" << arrayV[edgeVec[indexEdge].vertexB].name << " ";
		cout << edgeVec[indexEdge].value << endl;
		edgeSelected[edgeCount] = edgeVec[indexEdge];
		edgeCount++;
		ind = edgeVec[indexEdge].vertexB;
		arrayV[ind].isVisited = true;
	}
}

int graph::selectMinEdgeIndex(){
	int minIndex;
	for (int i = 0; i<int(edgeVec.size()); i++){
		if (edgeVec[i].isSelected == false && arrayV[edgeVec[i].vertexB].isVisited == false){
			minIndex = i;
			break;
		}
	}

	for (int i = minIndex + 1; i<int(edgeVec.size()); i++){
		if (edgeVec[i].isSelected == false && edgeVec[minIndex].value > edgeVec[i].value && arrayV[edgeVec[i].vertexB].isVisited == false){
			minIndex = i;
		}
	}

	return minIndex;
}