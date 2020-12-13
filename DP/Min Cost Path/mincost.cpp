#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//bottom up 
int min_cost(int a[100][100], int m, int n) {
	vector<vector<int> > dp(100, vector<int> (100,0));
	for(int i=0;i<m;i++) {
    	for(int j=0;j<n;j++) {
    		if(i==0 and j==0) {
    			dp[i][j] = a[0][0];
    		}
    		else if(i==0) {
    			dp[i][j] = dp[0][j-1] + a[0][j];
    		}
    		else if(j==0) {
    			dp[i][j] = dp[i-1][0] + a[i][0];
    		}
    		else {
    			dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + a[i][j];
    		}
    	}
    }
    return dp[m-1][n-1];
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int m,n;
    cin>>m>>n;
    int a[100][100];
    for(int i=0;i<m;i++) {
    	for(int j=0;j<n;j++) {
    		cin>>a[i][j];
    	}
    } 
    cout<<min_cost(a,m,n);
    return 0;

}