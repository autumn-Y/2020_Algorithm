//2019015369_±è³ª¿µ_11802
#include <iostream>
using namespace std;

int main() {
	int N,M,K;
	cin>>N>>M>>K;
	
	int *A=new int[K];
	int *B=new int[K];
	for(int i=0;i<K;i++) {
		cin>>A[i]>>B[i];
	}
	
	int *input=new int[N];
	int *c=new int[M+1];
	
	for(int i=0;i<N;i++) {
		cin>>input[i];
	}
	
	for(int i=0;i<N;i++) {
		c[input[i]]+=1;
	}
	
	for(int i=1;i<=M;i++) {
		c[i]=c[i]+c[i-1];
	}
	
	for(int i=0;i<K;i++) {
		cout<<c[B[i]]-c[A[i]-1]<<"\n";
	}
	
	delete[] A;
	delete[] B;
	delete[] input; 
	delete[] c;
	
	return 0;
}
