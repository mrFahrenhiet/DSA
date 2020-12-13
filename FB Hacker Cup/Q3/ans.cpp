#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int max_timber(vector<pair<int,int> > &trees,int n) {
	for(int i=0;i<n;i++) {
		if()
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int T;
    int num = 1;
    vector<pair<int,int> > vp;
    while(T--) {
    	int N;
    	cin>>N;
    	for(int i=0;i<N;i++) {
    		int pi,hi
    		cin>>pi>>hi;
    		vp.push_back(make_pair(pi,hi));
    	}
    	// sort(vp.begin(),vp.end());
    	cout<<"Case #"<<num<<": "<<max_timber(vp,N);
    	vp.clear();
    	num++;
    }
    return 0;

}