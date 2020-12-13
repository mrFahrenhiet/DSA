#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long int

bool isValid(ll a[], ll n, ll st, ll ans) {
	int stu = 1;
	ll current_pages = 0;
	for(int i=0;i<n;i++) {
		if(current_pages+a[i]>ans) {
			stu++;
			current_pages=a[i];
			if(stu>st) {
				return false;
			}
		}
		else {
			current_pages+=a[i];
		}
	}
	return true;
}

int minpages(ll a[],ll n,ll st) {
	ll s=a[n-1],e=0;
	ll ans;
	for(int i=0;i<n;i++) {
		e+=a[i];
	}
	while(s<=e) {
		int m = (s+e)/2;
		if(isValid(a,n,st,m)) {
			ans = m;
			e = m-1;
		}
		else {
			s = m+1;
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
	ll t,n,stu;
	cin>>t;
	for(int p=0;p<t;p++) {
		cin>>n>>stu;
		ll a[n];
		for(int i=0;i<n;i++) {
			cin>>a[i];
		}
		cout<<minpages(a,n,stu)<<endl;
	}
	return 0;
}