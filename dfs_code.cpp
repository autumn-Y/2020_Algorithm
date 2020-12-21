//2019015369_±è³ª¿µ_11802

#include <iostream>
#include <vector>
using namespace std;

int ccNum;
class Graph {
	public:
		vector<vector<int> > adj;
		vector<bool> visited;
		int size;
		
		Graph(){}
		
		Graph(int n) {
			size=n;
			adj.resize(n);
			visited.resize(n);
		}

		void addEdge(int v, int w) {
			adj[v].push_back(w);
		}
		
		void dfsUtil(int i) {
			vector<int>::iterator next;
			visited[i]=true;
			
			for(next=adj[i].begin();next!=adj[i].end();next++) {
				if(visited[*next]==false) {
					dfsUtil(*next);
				}
			}
		}
		
		void dfs_cc() {
			int cnt=0;	
			for(int i=1;i<size;i++) {
				if(visited[i]==false) {
					dfsUtil(i);
					ccNum++;
				}
			}
		}
		
		
};

int main() {
	int N,M,v,w;
	cin>>N>>M;
	Graph g(N+1);
	
	for(int i=0;i<M;i++) {
		cin>>v>>w;
		g.addEdge(v,w);
	}

	g.dfs_cc();
	cout<<ccNum;
	
	return 0;
}
