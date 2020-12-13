#include<iostream>
using namespace std;
#define ll long long int

bool is_valid(ll n, ll m, ll x, ll y,ll mid) {
	ll tol_c = m+(n-mid)*y;
	ll c_needed = x*mid;
	if(tol_c>=c_needed) {
		return true;
	}
	return false;
}

int max_students(ll n, ll m, ll x, ll y) {
	ll s=0,e=n;
	ll ans=0;
	while(s<=e) {
		ll mid = (s+e)/2;
		if(is_valid(n,m,x,y,mid)) {
			s=mid+1;
			ans = mid;
		}
		else {
			e=mid-1;
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
	ll n,m,x,y;
	cin>>n>>m>>x>>y;
	cout<<max_students(n,m,x,y);
	return 0;
}