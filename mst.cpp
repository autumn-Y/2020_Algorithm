//2019015369_±è³ª¿µ_11802

#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
	private:
		vector<pair<int, edge> > G;
		vector<pair<int, edge> > T;
		int *parent;
		int V;
	
	public:
		Graph(int V);
		void addEdge(int x, int y, int w);
		int findSet(int i);
		void unionSet(int x, int y);
		void kruskal();
		void printTree();
};

Graph::Graph(int V) {
	parent=new int[V];
	for (int i=0;i<V;i++) {
		parent[i]=i;
	}

	G.clear();
	T.clear();
}

void Graph::addEdge(int x, int y, int w) {
	G.push_back(make_pair(w, edge(x, y)));
}

int Graph::findSet(int i) {
	if(i==parent[i]) {
		return i;
	}
	
	else {
		return findSet(parent[i]);
	}
}

void Graph::unionSet(int x, int y) {
	parent[x]=parent[y];
}

void Graph::kruskal() {
	int u,v;
	sort(G.begin(), G.end());
	for (int i=0;i<G.size();i++) {
		u=findSet(G[i].second.first);
		v=findSet(G[i].second.second);
    	
		if (u!=v) {
			T.push_back(G[i]);
			unionSet(u, v);
    	}
	}
}

void Graph::printTree() {
	printf("%d",T.size());
	for (int i=0;i<T.size();i++) {
		printf("\n%d %d %d", T[i].second.first, T[i].second.second, T[i].first);
		//cout<<"\n"<<T[i].second.first <<" "<< T[i].second.second <<" "<< T[i].first;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin>>n>>m;
	
	Graph g(n+1);
	
	for(int i=0;i<m;i++) {
		int x, y, w;
		cin>>x>>y>>w;
		g.addEdge(x,y,w);
	}
	
	g.kruskal();
	g.printTree();
	return 0;
}
