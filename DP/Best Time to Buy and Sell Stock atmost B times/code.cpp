#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//TC = O(n*k)
int maxProfit(vector<int> &v,int k) {
	int n = v.size();
	int dp[n+1][k+1];
	memset(dp,0,sizeof dp);
	for(int i=0;i<n;i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	for(int i=1;i<=k;i++) {
		int profDiff = INT_MIN;
		for(int j=1;j<n;j++) {
			profDiff = max(profDiff,dp[i-1][j-1]-v[j-1]);
			dp[i][j] = max(dp[i][j-1],profDiff+v[j]);
		}
	}
	return dp[k][n-1];
}

//TC = O(n^2*k)
int maxProfitO(vector<int> &v,int k) {
	int n = v.size();
	int dp[n+1][k+1];
	memset(dp,0,sizeof dp);
	for(int i=0;i<n;i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	for(int i=1;i<=k;i++) {
		for(int j=1;j<n;j++) {
			int maxTillNow = INT_MIN;
			for(int l=j-1;l>=0;l--) {
				maxTillNow = max(maxTillNow,v[j]-v[l]+dp[i-1][l]);
			}
			dp[i][j] = max(dp[i][j-1],maxTillNow);
		}
	}
	return dp[k][n-1];
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
    int k;
    cin>>k;
    cout<<maxProfitO(v,k);
    return 0;

}