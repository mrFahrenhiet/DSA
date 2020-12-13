#include<iostream>
#include<vector>
#include<deque>
using namespace std;
void higest_of_k(vector<int> &a,deque<int> &q,int n,int k) {
	int i=0;
	for(i=0;i<k;i++) {
		while(!q.empty() && a[i]>a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	for(;i<n;i++) {
		cout<<a[q.front()]<<" ";
		while(!q.empty() && q.front()<=i-k) {
			q.pop_front();
		}
		while(!q.empty() && a[i]>a[q.back()]) {
			q.pop_back();
		}
		q.push_back(i);
	}
	cout<<a[q.front()];
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	int n,k;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++) {
		int no;
		cin>>no;
		a.push_back(no);
	}
	cin>>k;
	deque<int> q(k);
	higest_of_k(a,q,n,k);
	return 0;
}
