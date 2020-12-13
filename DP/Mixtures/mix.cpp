#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[100][100];
ll sum(ll a[],ll i,ll j) {
	ll s=0;
	for(ll l=i;l<=j;l++) {
		s+=a[l];
		s%=100;
	}
	return s;
}
ll min_smoke(ll a[],ll i,ll j) {
	if(i>=j) {
		dp[i][j] = 0;
		return 0;
	}
	if(dp[i][j]!=-1) {
		return dp[i][j];
	}
	ll ans = INT_MAX;
	for(ll k=i;k<j;k++) {
		ans = min(ans,min_smoke(a,i,k)+min_smoke(a,k+1,j)+sum(a,i,k)*sum(a,k+1,j));
	}
	return dp[i][j] = ans;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    memset(dp,-1,sizeof dp);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++) {
    	cin>>a[i];
    }
    cout<<min_smoke(a,0,n-1);
    return 0;

}