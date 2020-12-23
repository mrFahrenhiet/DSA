#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    vector<int> v;
    vector<int> res;
    while(t--) {
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++) {
    		int no;
    		cin>>no;
    		v.push_back(no);
    	}
    	int i=0, j=n-1, c=0;
    	while(i<=j) {
    		if(c%2==0) {
    			res.push_back(v[i++]);
    		}
    		else {
    			res.push_back(v[j--]);
    		}
    		c++;
    	}
    	for(auto itr: res)
    		cout<<itr<<" ";
    	cout<<endl;
    	v.clear();
    	res.clear();
	}
    return 0;

}