#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int integerReplacement(int n) {
        if(n==1) return 0;
        if(n==INT_MAX) return 32;
        if(n%2==0) return integerReplacement(n/2) + 1;
        if(n%4==1 or n==3) return integerReplacement(n-1) + 1;
        return integerReplacement(n+1) + 1;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    cout<<integerReplacement(n);
    return 0;
}