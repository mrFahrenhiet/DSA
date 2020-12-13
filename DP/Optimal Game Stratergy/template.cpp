#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<int> > dp(35,vector<int> (35,0) );
// Top Down DP
int winner(ll a[],ll j,ll i) {
	if(i>j) {
		return 0;
	}
	if(dp[i][j]!=0) {
		return dp[i][j];
	}
	// int x = a[i] + winner(a,j-1,i+1);
	// int z = a[i] + winner(a,j,i+2);
	// int y = a[j] + winner(a,j-1,i+1);
	// int b = a[j] + winner(a,j-2,i);
	// int k = min(x,z); //both players try to play optimally
	// int s = min(y,b); //both players try to play optimally
	int k = a[i] + min(winner(a,j,i+2),winner(a,j-1,i+1));
	int s = a[j] + min(winner(a,j-1,i+1),winner(a,j-2,i));
	return dp[i][j] = max(k,s);
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
	// sort(a,a+n);
    ll money = winner(a,n-1,0);
    cout<<money;
    return 0;

}