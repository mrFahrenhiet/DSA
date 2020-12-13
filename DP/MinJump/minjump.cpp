#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[1005];
ll min_jumps(ll n,vector<ll> &v,ll i) {
	// static ll steps=0;
	if(i==n-1) {
		dp[i]=0;
		return 0;
	}
	if(v[i]==0) {
		return n+1;
	}
	if(dp[i]!=-1) {
		return dp[i];
	}
	ll ans = INT_MAX;
	for(ll k=1;k<=v[i] && i<n;k++) {
		ll t = min_jumps(n,v,i+k)+1;
		ans = min(ans,t);
	}
	return dp[i] = ans;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--) {
    	memset(dp,-1,sizeof dp);
    	vector<ll> jumps;
    	ll n;
    	cin>>n;
    	for(ll i=0;i<n;i++) {
    		ll no;
    		cin>>no;
    		jumps.push_back(no);
    	}
		int ans = min_jumps(n,jumps,0);
		if(ans>n) {
			cout<<INT_MAX<<endl;
		}
    	cout<<ans<<endl;
    }

    return 0;

}