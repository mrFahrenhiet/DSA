#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void insertion_sort(vector<int> &a) {
    for(int i=0;i<a.size()-1;i++) {
        int j = i+1;
        while(j>0 && a[j]<a[j-1]) {
            swap(a[j],a[j-1]);
            j--;
        }
    }
}

int main() {
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        v.push_back(no);
    }
    for(auto itr: v) {
        cout<<itr<<" ";
    }
    cout<<endl;
    insertion_sort(v);
    for(auto itr: v) {
        cout<<itr<<" ";
    } 
	return 0;
}