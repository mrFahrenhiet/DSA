#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[105][105];

int rod_cuttin(int n, int maxlen, int len[], int value[]) {
	if(n <= 0) return 0;
	if(dp[n][maxlen]!=-1) return dp[n][maxlen];
	if(maxlen >= len[n-1]) return dp[n][maxlen] = max(value[n-1] + rod_cuttin(n, maxlen - len[n-1], len, value),
		rod_cuttin(n-1, maxlen, len, value));
	return dp[n][maxlen] = rod_cuttin(n-1, maxlen, len, value);
}

int rod_cuttin_itr(int n, int maxlen, int len[], int value[]) {
	int t[105][105] = {0};
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=maxlen;j++) {
			if(i==0 or j==0) t[i][j] = 0;
			else {
				if(j >= len[i-1]) t[i][j] = max(value[i-1] + t[i][j-len[i-1]], t[i-1][j]);
				else t[i][j] = t[i-1][j];
			}
		}
	}
	return t[n][maxlen];
}

int main() {
	int n, maxlen;
	cin>>n>>maxlen;
	int len[n+1], value[n+1];
	for(int i=0;i<n;i++) {
		cin>>len[i];
	}

	for(int i=0;i<n;i++) {
		cin>>value[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<rod_cuttin(n, maxlen, len, value)<<endl;
	cout<<rod_cuttin_itr(n, maxlen, len, value)<<endl;
	return 0;
}