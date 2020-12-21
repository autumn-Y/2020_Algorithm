//2019015369_±è³ª¿µ_11802 

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

class Vertex {
	public:
		int id;
		int color;
		int visited;
		int finished;
		vector<int> adj;

	Vertex() {
		color=WHITE;
		visited=0;
		finished=0;
	}
};

int n,m=0;
int cycle=false;
int findTime=0;

bool compare(Vertex v1, Vertex v2) {
	return v1.finished < v2.finished;
}


void dfsUtil(Vertex v[], int now) {
	Vertex &nowV=v[now];
	
	nowV.visited=++findTime;
	nowV.color=GRAY;

	for(int i=0;i<nowV.adj.size();i++) {
		int next=nowV.adj[i];
		Vertex &nextV=v[next];

		if(nextV.color==GRAY) {
			cycle=true;
			return;
		}
		
		else if(nextV.color==WHITE) {
			dfsUtil(v,next);
		}

		if(cycle) {
			return;
		}
	}

	nowV.color=BLACK;
	nowV.finished=++findTime;

}

void dfs(Vertex v[]) {
	for(int i=1;i<=n;i++) {
		if(v[i].color==WHITE) {
			dfsUtil(v,i);
			if(cycle) {
				return;
			}
		}
	}
}

void printTree(Vertex v[]){ 
	sort(v+1, v+(n+1), compare);

	for(int i=n;i>=1;i--) {
		printf("%d ",v[i].id);
	}
}

int main(void){
	int x,y;

	scanf("%d %d",&n,&m);
	
	Vertex* v=new Vertex[n+1];

	for(int i=1;i<=n;i++){
		v[i].id=i;
	}
	
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		v[x].adj.push_back(y);
	}
	
	for(int i=1;i<=n;i++) {
		sort(v[i].adj.begin(),v[i].adj.end());
	}

	dfs(v);

	if(cycle) {
		printf("0\n");
	}
	
	else {
		printf("1\n");
		printTree(v);
		printf("\n");
	}
	
	return 0;
}
