#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[500][500];

int coinChange(int n, int arr[], int s) {
	if(s==0) return 1;
	if(n<=0) return 0;
	if(dp[n][s]!=-1) return dp[n][s];
	if(arr[n-1] <= s) return dp[n][s] = coinChange(n, arr, s - arr[n-1]) + coinChange(n-1, arr, s);
	return dp[n][s] = coinChange(n-1, arr, s); 
}

int coinChangeBottom(int n, int arr[], int s) {
	int t[s+1];
	memset(t, 0, sizeof(t));
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=s;j++) {
			if(i==0) t[j] = 0;
			if(j==0) t[j] = 1;
			if(arr[i-1] <= j) t[j] = t[j - arr[i-1]] + t[j];
			else t[j] = t[j];
		}
	}
	return t[s];
}

int main() {
	int n,t;
	int arr[n+1];
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	int s;
	cin>>s;
	memset(dp, -1, sizeof(dp));
	cout<<coinChange(n, arr, s)<<endl;
	cout<<coinChangeBottom(n, arr, s)<<endl;
	return 0;
}