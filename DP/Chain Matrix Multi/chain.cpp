#include <bits/stdc++.h>
using namespace std;


vector<vector<int> > dp(100,vector<int>(100,-1) );

int chain_multi(vector<int> &v, int i, int j) {
    if(i>=j) {
        dp[i][j] = 0;
        return 0;
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i;k<j;k++) {
        int cost = chain_multi(v,i,k) + chain_multi(v,k+1,j) + v[i]*v[k]*v[j];
        ans = min(ans,cost);
    }
    dp[i][j] = ans;
    return ans;
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
    cout<<chain_multi(v,0,n-1);

}