#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
public:
    unsigned long long int optimalKeysUtil(vector<vector<int>>& dp, int n, int l, int c) {
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[l][c];
        int op1 = 1 + optimalKeysUtil(dp, n-1, l+1, c);
        int op2 = 0;
        if(n-3>=0) op2 = l + optimalKeysUtil(dp, n-3, l+l, l);
        int op3 = 0;
        if(c>0) op3 = c + optimalKeysUtil(dp, n-1, l+c, c);
        return dp[n] = max(op1, max(op2, op3));
    }
    unsigned long long int optimalKeys(int N){
        if(N<7) return N;
        vector<vector<int>> dp(N,-1);
        return optimalKeysUtil(dp, N-1, 1, 0) + 1;
    }
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.optimalKeys(n)<<endl;
    }
    return 0;

}