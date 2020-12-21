// 2019015369_±è³ª¿µ_11802

#include <iostream>
using namespace std;

int main() {
	int len;
	cin>>len;
	int *arr=new int[len];
	for(int i=0;i<len;i++) {
		cin>>arr[i];
	}
	
	int key,index;
	for(int i=1;i<len;i++) {
		key=arr[i];
		index=i;
		
		while(index>0 && arr[index-1]<key) {
			arr[index]=arr[index-1];
			index--;
		}
		arr[index]=key;
	}
	
	for(int i=0;i<len;i++) {
		if(i>0 && arr[i-1]==arr[i]) {
			continue;
		}
		cout<<arr[i]<<"\n";
	}
	
	delete []arr;
	return 0;
}

