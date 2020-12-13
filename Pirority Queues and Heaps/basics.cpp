#include<bits/stdc++.h>
using namespace std;
void insert_heap(vector<int> &a,int d) {
	a.push_back(d);
	int i=a.size()-1;
	while(a[i]>=a[(i-1)/2] && i>0) {
		swap(a[i],a[(i-1)/2]);
		i = (i-1)/2;
	}
	return;
}
void down_heap(vector<int> &a,int i) {
	int left_i = 2*i+1;
	int right_i = 2*i+2;
	int large = i;
	if(left_i>=a.size() and right_i>=a.size()) {
		return;
	}
	if(left_i<a.size() and a[left_i]>a[large] ) {
		large = left_i;
	}
	if(right_i<a.size() and a[right_i]>a[large]) {
		large = right_i;
	}
	if(large==i)
		return;
	swap(a[i],a[large]);
	down_heap(a,large);
	return;
}
void delete_heap(vector<int> &a) {
	swap(a[0],a[a.size()-1]);
	a.pop_back();
	down_heap(a,0);
}

void up_heap(vector<int> &a,int idx) {
	if(idx<=0) {
		return;
	}
	int p_idx = (idx-1)/2;
	if(a[idx]>a[p_idx]) {
		swap(a[idx],a[p_idx]);
		up_heap(a,p_idx);
	}
	else {
		return;
	}
}
//Delete From any index
void delete_from_any(vector<int> &a,int idx) {
	a[idx] = INT_MAX;
	up_heap(a,idx);
	delete_heap(a);
	return;
}
// void push(vector<int> &a,int d) {
// 	a.push_back(d);
// 	int i = a.size()-1;
// 	up_heap(a,d,i);
// 	return;
// }
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
    	insert_heap(heap,no);
    }
    for(int j=0;j<heap.size();j++) {
    	cout<<heap[j]<<" ";
    }
    delete_from_any(heap,3);
    cout<<endl;
    for(int j=0;j<heap.size();j++) {
    	cout<<heap[j]<<" ";
    }
    return 0;

}