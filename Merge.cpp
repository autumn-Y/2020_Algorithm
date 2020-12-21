// 2019015369_±è³ª¿µ_11802

#include <iostream>
using namespace std;

void merge(int list[],int p,int q,int r) {
	int a=p;
	int b=q+1;
	int c=p;
	int *merge_tmp=new int[r+1];
	
    while(a<=q && b<=r) {
        if(list[a]>=list[b]) {
			merge_tmp[c++] = list[a++];
		}
        else {
			merge_tmp[c++] = list[b++];
		}
    }
    while(a<=q) merge_tmp[c++] = list[a++];
    while(b<=r) merge_tmp[c++] = list[b++];
    for(int i=p;i<=r;i++) {
		list[i] = merge_tmp[i];
	}
    
    delete[] merge_tmp;
}

void merge_sort(int list[],int p,int r) {
	int q;
    if(p<r) {
        q = (p+r)/2;
        merge_sort(list,p,q);
        merge_sort(list,q+1,r);
        merge(list,p,q,r);
    }
}


int main() {
	int len;
	cin>>len;
	int *arr=new int[len];
	
	for(int i=0;i<len;i++) {
		cin>>arr[i];
	}
	
    merge_sort(arr,0,len-1);
    
    for(int i=0;i<len;i++) {
		if(i>0 && arr[i-1]==arr[i]) {
			continue;
		}
		cout<<arr[i]<<"\n";
	}
	
	delete []arr;
	return 0;
}
