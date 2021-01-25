#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int solveKnapsak(vector<int>& sz, vector<int>& val, int dp[2005][2005] , int s, int n) {
    if(n < 0 || s < 0) return 0;
    if(dp[n][s]!=-1) return dp[n][s];
    int incs = INT_MIN, exl = INT_MIN;
    if(s >= sz[n-1]) incs = val[n-1] + solveKnapsak(sz, val, dp, s-sz[n-1], n-1);
    exl = solveKnapsak(sz, val, dp, s, n-1);
    return dp[n][s] = max(incs, exl);
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
    int dp[2005][2005] = {-1};
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