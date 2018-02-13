#include <iostream>
#include <queue>
#include "graph.h"
using namespace std;

void graph::addVertex(const vertex& _v){
	nds[preNum] = _v;
	preNum++;
}

void graph::addEdge(edge& _e1, edge& _e2){
	_e1.nextEdge=nds[_e1.preV].firstEdge;
	nds[_e1.preV].firstEdge = &_e1;


	_e2.nextEdge = nds[_e2.preV].firstEdge;
	nds[_e2.preV].firstEdge = &_e2;
}

void graph::DepthFirstSearch(int _i){
	cout << nds[_i].Vdata << " ";
	nds[_i].isVisited = true;
	edge *e = nds[_i].firstEdge;
	while (e != NULL){
		if (nds[e->nextV].isVisited == false)
			DepthFirstSearch(e->nextV);
		e = e->nextEdge;
	}
	return;
}

void graph::initVertex(){
	for (int i = 0; i < maxVertex; i++){
		nds[i].isVisited = false;
	}
	cout << endl;
}

void graph::BreadthFirstSearch(int _i){
	cout << nds[_i].Vdata << " ";
	nds[_i].isVisited = true;
	queue<int> q;
	q.push(_i);
	while (!q.empty()){
		int i = q.front();
		q.pop();
		edge* e = nds[i].firstEdge;
		while (e != NULL){
			if (nds[e->nextV].isVisited == false){
				cout << nds[e->nextV].Vdata << " ";
				nds[e->nextV].isVisited = true;
				q.push(e->nextV);
			}
			e = e->nextEdge;
		}
	}
	cout << endl;
}