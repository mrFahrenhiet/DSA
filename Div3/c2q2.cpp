#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bool newYear(int n) {
    if(n<2020) return false;
    if(n>2020 and n<2021) return false;
    if(n%2020==0 or n%2021==0) return true;
    for(int i=0;i<496;i++) {
        int t = n - i*2021;
        if(t>=2020 and t%2020==0) return true;
    }
    return false;
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
        int n;
        cin>>n;
        bool x = newYear(n);
        if(x) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;

}