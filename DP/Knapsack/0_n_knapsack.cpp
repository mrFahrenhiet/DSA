#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int knapsackTopDown(vector<int> &sz, vector<int> &value, vector<vector<int>>& dp, int s, int i) {
	if(i>=value.size() or s<=0) return 0;
	if(dp[s][i]!=-1) return dp[s][i];
	int x = 0, y = 0;
	if(s - sz[i] >= 0) x = knapsackTopDown(sz, value, dp, s-sz[i], i) + value[i];
	y = knapsackTopDown(sz, value, dp, s, i+1);
	return dp[s][i] = max(x, y);
}

int knapsackBottomUp(vector<int> &sz, vector<int> &value, int s) {
	vector<int> dp(s+1, 0);
	for(int i=0;i<sz.size();i++) {
		for(int j=1;j<=s;j++)
			if(j - sz[i] >= 0) dp[j] = max(dp[j], dp[j-sz[i]] + value[i]); 
	}
	return dp[s];
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
    vector<int>sz;
    vector<int> value;
    vector<vector<int>> dp(s+1, vector<int>(n+1,-1));
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	sz.push_back(no);
    }
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	value.push_back(no);
    }
    cout<<knapsackBottomUp(sz, value, s);
    return 0;

}