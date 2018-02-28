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
	edgeSelKruskal = new edge[maxVertex - 1];
	edgeLib.clear();
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

void graph::kruskal(){
	//collect all the edges into a vector
	for (int i = 0; i < maxVertex; i++)
		for (int j = i; j < maxVertex; j++)
			if (linkMatrix[i*maxVertex + j] != 0){
				edge e;
				e.vertexA = i;
				e.vertexB = j;
				e.value = linkMatrix[i*maxVertex + j];
				edgeLib.push_back(e);
			}

	while (edgeCount < maxVertex - 1){
		int indexEdge = minValueEdge();
		edgeLib[indexEdge].isSelected = true;
		int vA = edgeLib[indexEdge].vertexA;
		int vB = edgeLib[indexEdge].vertexB;
		int vecIndexA, vecIndexB;
		vecIndexA = getVecIndex(vA);
		vecIndexB = getVecIndex(vB);
		if (vecIndexA == -1 && vecIndexB == -1){
			edgeSelKruskal[edgeCount] = edgeLib[indexEdge];
			edgeCount++;
			vector<int> _v;
			_v.push_back(vA);
			_v.push_back(vB);
			verVec.push_back(_v);
		}
		else
			if (vecIndexA == -1 && vecIndexB != -1){
				edgeSelKruskal[edgeCount] = edgeLib[indexEdge];
				edgeCount++;
				verVec[vecIndexB].push_back(vA);
			}
			else
				if (vecIndexA != -1 && vecIndexB == -1){
					edgeSelKruskal[edgeCount] = edgeLib[indexEdge];
					edgeCount++;
					verVec[vecIndexA].push_back(vB);
				}
				else
					if (vecIndexA != -1 && vecIndexB != -1 && vecIndexA != vecIndexB){
						edgeSelKruskal[edgeCount] = edgeLib[indexEdge];
						edgeCount++;
						if (vecIndexA < vecIndexB){
							mergeVector(verVec[vecIndexA], verVec[vecIndexB]);
						}
						else{
							mergeVector(verVec[vecIndexB], verVec[vecIndexA]);
						}
					}

		if (vecIndexA != -1 && vecIndexB != -1 && vecIndexA == vecIndexB)
			continue;

		cout << arrayV[edgeLib[indexEdge].vertexA].name << "-->" << arrayV[edgeLib[indexEdge].vertexB].name << " ";
		cout << edgeLib[indexEdge].value << endl;
	}
}

int graph::minValueEdge(){
	int i = 0;
	int minIndex = -1;
	for (; i < edgeLib.size(); i++){
		if (edgeLib[i].isSelected == false){
			minIndex = i;
			break;
		}
	}
	if (i == int(edgeLib.size()))
		return -1;

	for (; i < edgeLib.size(); i++){
		if (edgeLib[minIndex].value > edgeLib[i].value && edgeLib[i].isSelected == false)
			minIndex = i;
	}
	return minIndex;
}

int graph::getVecIndex(int v){
	for (int i = 0; i<int(verVec.size()); i++){
		for (int j = 0; j<int(verVec[i].size()); j++){
			if (v == verVec[i][j])
				return i;
		}
	}
	return -1;
}

void graph::mergeVector(vector<int> & v1, vector<int> v2){
	for (int i = 0; i<int(v2.size()); i++){
		v1.push_back(v2[i]);
	}
}