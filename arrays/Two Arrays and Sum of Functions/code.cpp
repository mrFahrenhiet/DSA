#include<bits/stdc++.h>
#define ll long long int
#define MOD 998244353
using namespace std;

bool comp(ll a1, ll a2) {
	return a1>a2;
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
    vector<ll> a;
    vector<ll> b;
    for(ll i=0;i<n;i++) {
    	ll no;
    	cin>>no;
    	no *= (i+1)*(n-i);
    	a.push_back(no);
    }
    for(int i=0;i<n;i++) {
    	ll no;
    	cin>>no;
    	b.push_back(no);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), comp);
    ll sum = 0;
    for(int i=0;i<n;i++) {
    	sum += (a[i]%MOD)*(b[i]%MOD);
    	sum = sum%MOD;
    }
    cout<<sum%MOD<<endl;
    return 0;
}