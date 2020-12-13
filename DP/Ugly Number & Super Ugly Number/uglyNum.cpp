#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> uglyNum(10000,-1);
ll getUglyNum(ll n) {
	if(uglyNum[n-1]!=-1) {
		return uglyNum[n-1];
	}
	uglyNum[0] = 1;
	ll i2,i3,i5;
	i2=0;
	i3=0;
	i5=0;
	ll next_2 = 2;
	ll next_3 = 3;
	ll next_5 = 5;
	for(ll i=1;i<=n;i++) {
		ll next_nos = min(next_2,min(next_3,next_5));
		uglyNum[i] = next_nos;
		if(next_nos==next_2) {
			i2+=1;
			next_2 = uglyNum[i2]*2;
		}
		if(next_nos==next_3) {
			i3+=1;
			next_3 = uglyNum[i3]*3;
		}
		if(next_nos==next_5) {
			i5+=1;
			next_5 = uglyNum[i5]*5;
		}
	}
	return uglyNum[n-1];
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
	cin>>t;
	while(t--) {
    	ll n;
    	cin>>n;
    	cout<<getUglyNum(n)<<endl;
	}
    return 0;

}