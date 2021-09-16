#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int mcm(int arr[], int n, int i, int j) {
	if(i>=j) return 0;
	if(dp[i][j]!=-1) return dp[i][j];
	int ans = INT_MAX;
	for(int k=i;k<j;k++) {
		int temp_sol = mcm(arr, n, i, k) + mcm(arr, n, k+1, j) + arr[i]*arr[k]*arr[j];
		ans = min(ans, temp_sol);
	}
	return dp[i][j] = ans;
}
int main() {
	int arr[1000], n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	memset(dp, -1, sizeof(dp));
	cout<<mcm(arr, n, 1, n-1)<<endl;
	return 0;
}