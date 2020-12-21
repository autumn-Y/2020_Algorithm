//2019015369_±è³ª¿µ_11802
#include <iostream>
using namespace std;

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
	int size;
	cin>>size;
	int k;
	cin>>k;
	int *arr=new int[size];
	
	for(int i=0;i<size;i++) {
		cin>>arr[i];
	}

	BuildMaxHeap(arr,size);
	HeapSort(arr,size); 
	for(int i=0;i<k;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	
	for(int i=k;i<size;i++) {
		cout<<arr[i]<<" ";
	}
	
	delete[] arr;
	return 0;
}
