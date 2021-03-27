#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int minimumOperationsReq(string str, int k, int n) {
    int goodness = 0;
    int i = 0, j = n-1;
    while(i<j) {
        if(str[i]!=str[j]) goodness++;
        i++;
        j--;
    }
    return abs(goodness - k);
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t, i = 1;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        int minOpp = minimumOperationsReq(str, k, n);
        cout<<"Case #"<<i<<": "<<minOpp<<endl;
        i++;
    }
    return 0;

}