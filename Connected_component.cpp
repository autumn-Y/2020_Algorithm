//2019015369_±è³ª¿µ_11802

#include <iostream>
#include<cstdio>
#include <vector>
using namespace std;

int findParent(vector<int> &parent, int x) {
	if(parent[x]==x) {
		return x;
	}
	
	parent[x]=findParent(parent,parent[x]);
	
	return parent[x];
}

void unionSet(vector<int> &parent, int a, int b) {
	a=findParent(parent,a);
	b=findParent(parent,b);
	
	if(a<b) {
		parent[b]=a;
	}
	
	else{
		parent[a]=b;
	}
}

bool isInSet(vector<int> &parent, int size, int n) {
	for(int i=1;i<=n;i++) {
		if(n==parent[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	int N,M,v,w;
	int cnt=0;
	cin>>N>>M;
	
	vector<int> parent(N+1,0);
	
	for(int i=1;i<=N;i++) {
		parent[i]=i;
	}
	
	for(int i=0;i<M;i++) {
		scanf("%d %d",&v,&w);
		unionSet(parent,v,w);
	}
	
	for(int i=1;i<=N;i++) {
		if(isInSet(parent,N,i)) {
			cnt++;
		}
	}
	
	cout<<cnt<<"\n";

}
