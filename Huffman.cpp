//2019015369 ±è³ª¿µ 11802

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int count;

class MinHeapNode {
	public:
		int freq;
		int depth;
		
		MinHeapNode *left;
		MinHeapNode *right;
		
		MinHeapNode(int freq) {
			this->freq=freq;
			depth=0;
			left=NULL;
			right=NULL;
		}
};

class Compare{
	public:
		bool operator() (MinHeapNode *n1, MinHeapNode *n2) {
			return n1->freq>n2->freq;
		}
};

MinHeapNode* HuffmanTree(priority_queue<MinHeapNode*, vector<MinHeapNode*>, Compare> pq) {
	MinHeapNode *left, *right, *top;
	
	while(pq.size()!=1) {
		left=pq.top();
		pq.pop();
		
		right=pq.top();
		right->depth++;
		pq.pop();
		
		top=new MinHeapNode(left->freq+right->freq);
		top->left=left;
		top->right=right;
		
		pq.push(top);
	}
	
	return pq.top();
}

void codeLength(MinHeapNode *node) {
	if(!node) {
		return;
	}
	
	if(!node->left && !node->right) {
		count+=(node->freq)*(node->depth);
	}
	
	if(node->left) {
		node->left->depth=(node->depth)+1;
	}
	
	if(node->right) {
		node->right->depth=(node->depth)+1;
	}
	
	codeLength(node->left);
	codeLength(node->right);
}

int main() {
	int N;
	cin>>N;
	
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, Compare> pq;
	
	string data;
	int freq;
	for(int i=0;i<N;i++) {
		cin>>data>>freq;
		MinHeapNode *newNode=new MinHeapNode(freq);
		pq.push(newNode);
	}
	
	int S;
	cin>>S;
	
	MinHeapNode *root=HuffmanTree(pq);
	codeLength(root);
	
	int fixed_length=int(ceil(log(N)/log(2)));
	cout<<fixed_length*S<<"\n\n";
	cout<<count;
	
	return 0;
}
