//2019015369_±è³ª¿µ_11802
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp=a;
	a=b;
	b=temp;
}

void maxHeapify(int heap[], int hlast, int hparent) {
    int left=(hparent*2)+1;
    int right=left+1;           
    int biggest=left;      
 
    if(left>hlast)
        return;
    if(right>hlast)
        biggest=left;
    else   
        biggest=(heap[left]<=heap[right]) ? right:left;
 
    if(heap[hparent]<heap[biggest])
    {
        swap(heap[hparent],heap[biggest]);
        maxHeapify(heap,hlast,biggest);
    }
 
    return;
}
void BuildMaxHeap(int heap[],int hsize) {
	int parent=(hsize/2)-1;
	int last=hsize-1;
	for(;parent>=0;parent--) {
		maxHeapify(heap,last,parent);
	}
}

int main() {
	int *arr=new int[100000];
	int *max=new int[100000];
	int alen=0;
	int mlen=0;
	int index,value;
	
	int a;
	cin>>a;
	while(a!=0) {
		if(a==1) {
			cin>>arr[alen];
			alen+=1;	
			BuildMaxHeap(arr,alen);
		}

		else if(a==2) {
			swap(arr[0],arr[alen-1]); 
			max[mlen]=arr[alen-1];
			mlen++;
			alen--;
			BuildMaxHeap(arr,alen);
		}
		 
		else if(a==3) {
			cin>>index>>value;
			arr[index-1]=value;
			BuildMaxHeap(arr,alen); 
		}
		cin>>a;
	}
	
	for(int i=0;i<mlen;i++) {
		cout<<max[i]<<" ";
	}
	cout<<"\n";
	for(int i=0;i<alen;i++) {
		cout<<arr[i]<<" ";
	}
	
	delete[] arr;
	delete[] max;
	return 0;
}
