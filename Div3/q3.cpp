#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int smallestNos(int x) {
	if(x%10==0 and x!=10)
		return -1;
	if(x/10==0)
		return x;
	(N % 9 + 1)* pow(10, (N / 9)) - 1;

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
    	int x;
    	cin>>x;
    	cout<<smallestNos(x)<<endl;
    }
    return 0;

}