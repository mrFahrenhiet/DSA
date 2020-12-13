#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
bool is_valid(ll a[],ll n, ll tol_cows, ll mid) {
	int j=0;
	ll cows = 1;
	for(int i=1;i<n;i++) {
		ll diff = a[i] - a[j];
		if(diff>=mid) {
			cows++;
			j=i;
			// cout<<cows<<endl;
			if(cows>=tol_cows) {
				return true;
			}
		}
	}
	return false;
}
int allot_stall(ll a[],ll n, ll c) {
	sort(a,a+n);
	ll s=0,e=a[n-1];
	int ans;
	while(s<=e) {
		int m  = (e+s)/2;
		if(is_valid(a,n,c,m)) {
			ans = m;
			s=m+1;
		}
		else {
			e=m-1;
		}
	}
	return ans;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	ll n,c;
	cin>>n>>c;
	ll a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int x = allot_stall(a,n,c);
	cout<<x;
	return 0;
}