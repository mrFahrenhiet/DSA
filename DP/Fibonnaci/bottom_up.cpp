#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll fib(ll n,vector<ll> d) {
    for(int i=0;i<=n;i++) {
        if(i==0 or i==1) {
            d[i] = i;
        }
        else {
            d[i] = d[i-1] + d[i-2];
        }
    }
    return d[n];
}
ll fib_space_opt(ll n) {
    int a = 0;
    int b = 1;
    int c;
    if(n==0 or n==1) {
        return n;
    }
    for(int i=2;i<=n;i++) {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main() {
	// #ifndef ONLINE_JUDGE
    // // for getting input from input.txt
    // freopen("input.txt", "r", stdin);
    // // for writing output to output.txt
    // freopen("output.txt", "w", stdout);
    // #endif
    ll n;
    cin>>n;
    vector<ll> dp(1000,0);
    cout<<fib_space_opt(n);
    return 0;

}