//2019015369_±è³ª¿µ_11802

#include <iostream>
using namespace std;

int** Rodcut(int *pr, int **rs, int n) {
	rs[0][0]=rs[1][0]=0;
	int q;
	for(int j=1;j<n+1;j++) {
		q=-1;
		for(int i=1;i<j+1;i++) {
			if (q<pr[i]+rs[0][j-i]) {
				q=pr[i]+rs[0][j-i];
				rs[1][j]=i;
			}
		}
		rs[0][j]=q;
	}
	
	return rs;
}

int main() {
	int N;
	cin>>N;
	
	int *p=new int[N+1];
	for(int i=1;i<N+1;i++) {
		cin>>p[i];
	}
	
	int **RS=new int*[2];
	for(int i=0;i<2;i++) {
		RS[i]=new int[N+1];
	}
	
	RS=Rodcut(p,RS,N);
	cout<<RS[0][N]<<"\n";
	
	while(N>0) {
		cout<<RS[1][N]<<" ";
		N=N-RS[1][N];
	}
	
	delete[] p;
	for(int i=0;i<2;i++) {
		delete []RS[i];
	}
	delete []RS;
	
	return 0;
}
