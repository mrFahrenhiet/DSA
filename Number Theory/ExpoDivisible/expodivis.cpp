#include<iostream>
using namespace std;
#define ll long long int
int expomod(ll n, ll p, ll m) {
	if(p==0) {
		return 1;
	}
	return ((n%m)*expomod(n,p-1,m))%m;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
	ll a,b,c;
	cin>>a>>b>>c;
	ll ans = expomod(a,b,c);
	cout<<ans<<endl;
	return 0;
}