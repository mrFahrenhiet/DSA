#include<bits/stdc++.h>
#define ll long long int
using namespace std;

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
        double n;
        cin>>n;
        double x = log2(n);
        double y = round(x);
        if(x==y) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;

}