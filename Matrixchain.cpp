//2019015369_±è³ª¿µ_11802

#include<iostream>
using namespace std;

void matrix_chain(int **m, int **s, int *p, int n) {
	int j,q;
	for(int i=1;i<n+1;i++) {
		m[i][i]=0;
	}

	for(int l=2;l<n+1;l++) {
		for(int i=1;i<n-l+2;i++) {
			j=i+l-1;
			m[i][j]=214748364;
			for(int k=i;k<j;k++) {
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j]) {
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}

	cout<<m[1][n]<<"\n";
}

void print_opt_paren(int **s,int i, int j) {
	if(i==j) {
		cout<<i<<" ";
	}
	
	else {
		cout<<"( ";
		print_opt_paren(s,i,s[i][j]);
		print_opt_paren(s,s[i][j]+1,j);
		cout<<") ";
	}
}

int main() {
	int N;
	cin>>N;
	
	int *P=new int[N+1];
	for(int i=0;i<N+1;i++) {
		cin>>P[i];
	}
	
	int **M=new int*[N+1];
	for(int i=0;i<N+1;i++) {
		M[i]=new int[N+1];
	}
	
	int **S=new int*[N+1];
	for(int i=0;i<N+1;i++) {
		S[i]=new int[N+1];
	}
	
	matrix_chain(M,S,P,N);
	print_opt_paren(S,1,N);
	
	delete []P;
	for(int i=0;i<N;i++) {
		delete []M[i];
	}
	delete []M;
	
	for(int i=0;i<N-1;i++) {
		delete []S[i];
	}
	delete []S;
	return 0;
}
