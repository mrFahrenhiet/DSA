#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[5000];
ll max_val(vector<ll> &size, vector<ll> &value, ll n, ll s) {
	for(ll i=0;i<=s;i++) {
		for(ll j=0;j<n;j++) {
			if(size[j]<=i) {
				dp[i] = max(dp[i],dp[i-size[j]]+value[j]);
			}
		}
	}
	return dp[s];
} 
int main() {
    ll n,s;
    cin>>n>>s;
    vector<ll>size;
    vector<ll> value;
    memset(dp,0,sizeof dp);
    for(ll i=0;i<n;i++) {
    	ll no;
    	cin>>no;
    	size.push_back(no);
    }
    for(ll i=0;i<n;i++) {
    	ll no;
    	cin>>no;
    	value.push_back(no);
    }
    cout<<max_val(size,value,n,s);
    return 0;

}