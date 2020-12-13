#include <bits/stdc++.h>
#define ll long long int
using namespace std;


vector<ll> dp(1000,0);

// Top Down
ll pairs(ll n) {
    if(n<=1) {
        return 1;
    }
    if(dp[n]!=0) {
        return dp[n];
    }
    return dp[n] = pairs(n-1) + (n-1)*pairs(n-2);
}

// Bottom Up
ll pairs_btm(ll n) {
    dp[0] = 1;
    dp[1] = 1;
    for(ll i=2;i<=n;i++) {
        dp[i] = dp[i-1] + (i-1)*dp[i-2];
    }
    return dp[n];
}

// Bottom up space complexity optimization
ll pair_opti(ll n) {
	int prev=1,p_prev=1,next=1;
	for(int i=2;i<=n;i++) {
		next = prev + (i-1)*p_prev;
		p_prev = prev;
		prev = next;
	}
	return next;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    ll ans = pair_opti(n);
    cout<<ans;
}
