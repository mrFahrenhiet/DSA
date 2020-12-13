#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll multiPeri(vector<ll> &l, vector<ll> &h, ll w) {
	ll ovl = 0;
	vector<int> p;
	// p.push_back(0);
	ll peri = 1 ;
	p.push_back(2*(w+h[0])%1000000007);
	ll Hhigh = h[0];
	ll Hidx = 0;
	for(ll i=1;i<l.size();i++) {
		if(l[i]<=l[i-1]+w) {
			// if(l[Hidx]+w<l[i]) {
			// 	p.push_back((p[i-1]+2*(l[i]+w-l[i-1]-w)+2*h[i]-h[i-1])%1000000007);
			// 	Hhigh = h[i];
			// 	Hidx = i;
			// }
			if(h[i]>Hhigh) {
				if(l[Hidx]+w<l[i]) {
					p.push_back((p[i-1]+2*(l[i]+w-l[i-1]-w)+2*h[i]-h[i-1])%1000000007);
				}
				else {
 					p.push_back((p[i-1]+2*(l[i]+w-l[i-1]-w)+2*(h[i]-Hhigh))%1000000007);
				}
				Hhigh = h[i];
				Hidx = i;
			}
			else {
				p.push_back((p[i-1]+2*(l[i]-l[i-1]))%1000000007);
			}
		}
		else {
			p.push_back((p[i-1]+2*(w+h[i]))%1000000007);
			Hhigh = h[i];
			Hidx = i;
		}
	}
	for(auto itr: p) {
		peri = (peri*itr)%1000000007;
	}
	// for(auto itr: p) {
	// 	cout<<itr<<" ";
	// }
	// cout<<endl;
	return peri%1000000007;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ll t;
    int o = 0;
    cin>>t;
    vector<ll> l;
    vector<ll> lkn;
    vector<ll> h;
    vector<ll> hkn;
    while(t--) {
    	ll n,k,w;
    	cin>>n>>k>>w;

    	for(ll i=0;i<k;i++) {
    		ll no;
    		cin>>no;
    		l.push_back(no);
    	}
    	for(ll i=0;i<4;i++) {
    		ll no;
    		cin>>no;
    		lkn.push_back(no);
    	}
    	for(ll i=0;i<k;i++) {
    		ll no;
    		cin>>no;
    		h.push_back(no);
    	}
    	for(ll i=0;i<4;i++) {
    		ll no;
    		cin>>no;
    		hkn.push_back(no);
    	}
    	if(n>k) {
    		for(ll i=k;i<n;i++) {
    			l.push_back((lkn[0]*l[i-2] + lkn[1]*l[i-1] + lkn[2])%lkn[3]+1);
    			h.push_back((hkn[0]*h[i-2] + hkn[1]*h[i-1] + hkn[2])%hkn[3]+1);
    		}
    	}
  //   	for(auto it: l) {
  //   		cout<<it<<" ";
  //   	}
  //   	cout<<endl<<endl;
		// for(auto it: h) {
		// 	cout<<it<<" ";
		// }
  //   	cout<<endl<<endl;
    	ll x = multiPeri(l,h,w);
    	cout<<"Case #"<<o+1<<": "<<x<<endl;
    	l.clear();
    	h.clear();
    	lkn.clear();
    	hkn.clear();
    	o++;
    }
    return 0;

}