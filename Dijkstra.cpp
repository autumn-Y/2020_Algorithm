//2019015369_±è³ª¿µ_11802

#include <utility>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
	int n;
	vector<pair<int, int> > *adj;
	
	public:
		Graph() {}
		
		Graph(int size) {
			n=size;
			adj=new vector<pair<int, int> > [size];
		}
		
		void addEdge(int x, int y, int w) {
			adj[x].push_back(make_pair(y,w));
		}
		
		void dijkstra(int *dist, int source) {
			for(int i=1;i<n;i++) {
				dist[i]=99999;
			}
			
			priority_queue<pair<int,int> > q;
			
			q.push({1, source});
			dist[source]=0;
			
			while(!q.empty()) {
				int cost=-q.top().first;
				int here=q.top().second;
				q.pop();
				
				if(dist[here]<cost) {
					continue;
				}
				
				for(int i=0;i<adj[here].size();i++) {
					int next=adj[here][i].first;
					int ncost=adj[here][i].second;
					
					if(dist[next] > dist[here]+ncost) {
						dist[next]=dist[here]+ncost;
						q.push({-dist[next], next});
					}
				}	
			}
		}

};

void findMax(int *dist, int size) {
	int max=dist[1];
	for(int i=2;i<size;i++) {
		if(max<dist[i]) {
			max=dist[i];
		}
	}
	cout<<max;
}

int main() {
	int N,M,x,y,w;
	cin>>N>>M;
	
	Graph g(N+1);
	for(int i=0;i<M;i++) {
		cin>>x>>y>>w;
		g.addEdge(x,y,w);
	}
	
	int *dist=new int[N+1];
	
	g.dijkstra(dist, 1);
	findMax(dist, N+1);
	
	delete[] dist;
	
	return 0;
}
