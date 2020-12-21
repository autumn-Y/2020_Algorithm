//2019015369_±è³ª¿µ_11802

#include <iostream>
using namespace std;

void Fastestway(int **a, int**t, int *e, int *x, int n) {
	int **s=new int*[2];
	for(int i=0;i<2;i++) {
		s[i]=new int[n];
	}

	int **l=new int*[2];
	for(int i=0;i<2;i++) {
		l[i]=new int[n];
	}
	
	int fast,line;
	
	s[0][0]=e[0]+a[0][0];
	s[1][0]=e[1]+a[1][0];
	
	for(int i=1;i<n;i++) {
		if (s[0][i-1] <= s[1][i-1]+t[1][i-1]) {
			s[0][i]=s[0][i-1]+a[0][i];
			l[0][i]=1;
		}
		
		else {
			s[0][i]=s[1][i-1]+t[1][i-1]+a[0][i];
			l[0][i]=2;
		}
		
		if (s[1][i-1] <= s[0][i-1]+t[0][i-1]) {
			s[1][i]=s[1][i-1]+a[1][i];
			l[1][i]=2;
		}
		
		else {
			s[1][i]=s[0][i-1]+t[0][i-1]+a[1][i];
			l[1][i]=1;
		}
	}
	
	if (s[0][n-1]+x[0] <= s[1][n-1]+x[1]) {
		fast=s[0][n-1]+x[0];
		line=1; 
	}
	
	else {
		fast=s[1][n-1]+x[1];
		line=2;
	}
	
	cout<<fast<<"\n";
	
	int k=line;
	s[0][n-1]=k;
	s[1][n-1]=n;
	for(int j=n-1;j>0;j--) {
		k=l[k-1][j];
		s[0][j-1]=k;
		s[1][j-1]=j;
	}
	
	for(int i=0;i<n;i++) {
		cout<<s[0][i]<<" "<<s[1][i]<<"\n";
	}
	
	for(int i=0;i<2;i++) {
		delete []s[i];
	}
	delete []s;
	 
	for(int i=0;i<2;i++) {
		delete []l[i];
	}
	delete []l;
}


int main() {
	int n;
	cin>>n;
	int *e=new int[2];
	cin>>e[0]>>e[1];
	
	int *x=new int[2];
	cin>>x[0]>>x[1];
	
	int **a=new int*[2];
	for(int i=0;i<2;i++) {
		a[i]=new int[n];
	}
	for(int i=0;i<2;i++) {
		for(int j=0;j<n;j++) {
			cin>>a[i][j];
		}
	}
	
	int **t=new int*[2];
	for(int i=0;i<2;i++) {
		t[i]=new int[n-1];
	}
	for(int i=0;i<2;i++) {
		for(int j=0;j<n-1;j++) {
			cin>>t[i][j];
		}
	}
	
	Fastestway(a,t,e,x,n);
	
	delete[] e;
	delete[] x;
	for(int i=0;i<2;i++) {
		delete []a[i];
	}
	delete []a;
	for(int i=0;i<2;i++) {
		delete []t[i];
	}
	delete []t;
	
	return 0; 
}
