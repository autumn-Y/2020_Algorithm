//2019015369_±è³ª¿µ_11802
#include <iostream>
using namespace std;

bool search(int arr[],int size,int x) {
	for(int i=0;i<size;i++) {
		if(arr[i]==x) {
			return true;
		}
	}
	return false; 
}

void swap(int &a, int &b) {
	int temp=a;
	a=b;
	b=temp;
}

void BuildMaxHeap(int heap[],int hsize) {
	for(int i=1;i<hsize;i++) {
		int c=i;
		do{
			int root=(c-1)/2;
			if(heap[root]>heap[c]) {
				swap(heap[root],heap[c]);
			}
			c=root;
		}while(c!=0);
	}
}

void HeapSort(int heap[],int hsize) {
	for(int i=hsize-1;i>=0;i--) {
		swap(heap[i],heap[0]);
		
		int root=0;
		int c=1;
	
		do {
			c=2*root+1;
			if(c<i-1 && heap[c]>heap[c+1]) {
				c++;
			}
			if(c<i && heap[root]>heap[c]) {
				swap(heap[root],heap[c]);
			}
			
			root=c;
		}while(c<i);
	}
}

int main() {
	int N,M;
	cin>>N>>M;
	int *A=new int[N];
	int *B=new int[M];
	
	for(int i=0;i<N;i++) {
		cin>>A[i];
	}
	for(int i=0;i<M;i++) {
		cin>>B[i];
	}
	
	int count=0;
	if(N>=M) {
		BuildMaxHeap(B,M);
		HeapSort(B,M);
		for(int i=0;i<M;i++) {
			if(B[i]==B[i+1]) continue;
			bool find=search(A,N,B[i]);
			if(find) count++;
		}
	}
	
	else {
		BuildMaxHeap(A,N);
		HeapSort(A,N);
		for(int i=0;i<N;i++) {
			if(A[i]==A[i+1]) continue;
			bool find=search(B,M,A[i]);
			if(find) count+=1;
		}
	}
	
	cout<<count;
	
	delete[] A;
	delete[] B;
	
	return 0;
}
