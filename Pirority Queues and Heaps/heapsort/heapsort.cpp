#include<bits/stdc++.h>
using namespace std;
void down_heap(vector<int> &a,int i) {
	int left = 2*i+1;
	int right = 2*i+2;
	int large=i;
	if(left>=a.size() and right>=a.size()) {
		return;
	} 
	if(left<a.size() and a[left]>a[large]) {
		large = left;
	}
	if(right<a.size() and a[right]>a[large]) {
		large = right;
	}
	if(large == i) 
		return;
	swap(a[large],a[i]);
	down_heap(a,large);
}
void build_heap_down(vector<int> &a) {
	for(int j=a.size()-1;j>=0;j--) {
		down_heap(a,j);
	}
	return;
}
void down_heap_helper(vector<int> &a,int idx,int n) {
	int left = 2*idx+1;
	int right = 2*idx+2;
	int large=idx;
	if(n<=0) {
		return;
	}
	if(left>=n and right>=n) {
		return;
	} 
	if(left<n and a[left]>a[large]) {
		large = left;
	}
	if(right<n and a[right]>a[large]) {
		large = right;
	}
	if(large == idx) 
		return;
	swap(a[large],a[idx]);
	down_heap_helper(a,large,n);
}
void heapsort(vector<int> &a) {
	int heap_size = a.size();
	build_heap_down(a);
	for(int l=a.size()-1;l>=0;l--) {
		swap(a[0],a[l]);
		heap_size-=1;
		down_heap_helper(a,0,heap_size);
	}

}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> heap;
    int n;
    cin>>n;
    for(int j=0;j<n;j++) {
    	int no;
    	cin>>no;
    	heap.push_back(no);
    }
    heapsort(heap);
    for(int idx=0;idx<heap.size();idx++) {
    	cout<<heap[idx]<<" ";
    }
    return 0;

}