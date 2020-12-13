#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll fib(ll n,vector<ll> d) {
	if(n==1 or n==0) {
		return n;
	}
	if(d[n]!=0) {
		return d[n];
	}
	ll ans = fib(n-1,d)+fib(n-2,d);
	return d[n] = ans;
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
    vector<ll> dp(1000,0);
    cout<<fib(n,dp);
    return 0;

}