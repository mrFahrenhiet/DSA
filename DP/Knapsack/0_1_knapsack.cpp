#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int solveKnapsak(vector<int>& sz, vector<int>& val, int dp[105][105] , int s, int n) {
    if(n < 0 || s < 0) return 0;
    if(dp[n][s]!=-1) return dp[n][s];
    int incs = 0, exl = 0;
    if(s >= sz[n-1]) incs = val[n-1] + solveKnapsak(sz, val, dp, s-sz[n-1], n-1);
    exl = solveKnapsak(sz, val, dp, s, n-1);
    return dp[n][s] = max(incs, exl);
}

int knapsack_bu(vector<int>& sz, vector<int>& val, int dp[105][105], int s, int n) {
    for(int i=0;i<n+1;i++) {
        for(int j=0;j<s+1;j++) {
            if(!i || !j) dp[i][j] = 0;
            else {
                if(sz[i-1] <= j) dp[i][j] = max(val[i-1] + dp[i-1][j-sz[i-1]], dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][s];
}

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    vector<int> sz;
    vector<int> val;
    int dp[105][105] = {0};
    while(t--) {
        int s,n;
        cin>>s>>n;
        for(int i=0;i<n;i++) {
            int v,si;
            cin>>si>>v;
            sz.push_back(si);
            val.push_back(v);
        }
        cout<<solveKnapsak(sz, val, dp, s, n)<<endl;
        sz.clear();
        val.clear();
    }  
    return 0;
}