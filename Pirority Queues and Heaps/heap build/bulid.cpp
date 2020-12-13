#include<bits/stdc++.h>
using namespace std;
void up_heap(vector<int> &a,int i) {
	if(i<=0) {
		return;
	}
	if(i>=a.size()) {
		return;
	}
	int pi = (i-1)/2;
	if(a[i]>a[pi]) {
		swap(a[i],a[pi]);
		up_heap(a,pi);
	}
	else {
		return;
	}
}
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
void build_heap_up(vector<int> &a) {
	for(int i=1;i<a.size();i++) {
		up_heap(a,i);
	}
	return;
}
void build_heap_down(vector<int> &a) {
	for(int j=(a.size()-1/2);j>=1;j--) {
		down_heap(a,j);
	}
	return;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    vector<int> a;
    int n;
    cin>>n;
    for(int j=0;j<n;j++) {
    	int no;
    	cin>>no;
    	a.push_back(no);
    }
    build_heap_down(a);
    for(int k=0;k<a.size();k++) {
    	cout<<a[k]<<" ";
    }
    return 0;

}