#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int dp[100][100];
int max_val(vector<int> &size, vector<int> &value, int n, int s) {
	if(n<=0 || s<=0) {
        return 0;
    }
    int incs= 0, ex=0;
    if(size[n-1]<=s) {
        incs = max_val(size,value,n-1,s-size[n-1])+value[n-1];
    }
    if(dp[n][s]!=-1) {
        return dp[n][s];
    }
    ex = max_val(size,value,n-1,s);
    return dp[n][s] = max(incs,ex);
} 
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,s;
    cin>>n>>s;
    vector<int>size;
    vector<int> value;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	size.push_back(no);
    }
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	value.push_back(no);
    }
    cout<<max_val(size,value,n,s);
    return 0;

}