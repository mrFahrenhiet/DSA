#include<bits/stdc++.h>
using namespace std;
//bottom up dp
int nos_bst(int n) {
	vector<int> dp(100,0);
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=i;j++) {
            dp[i] += dp[j-1]*dp[i-j];
        }
	}
    return dp[n];
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
 	cout<<nos_bst(n);   
    return 0;

}