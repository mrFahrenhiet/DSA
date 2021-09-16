#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int dp[105][105];

int min_sub_diff_brute(int arr[], int n, int sum, int s1) {
	if(n==0) return abs(sum - 2*s1);
	return min(min_sub_diff_brute(arr, n-1, sum, s1 + arr[n-1]), min_sub_diff_brute(arr, n-1, sum, s1));
}

int min_sub_diff_mem(int arr[], int n, int sum, int s1) {
	if(n==0) return abs(sum - 2*s1);
	if(dp[n][sum]!=-1) return dp[n][sum];
	return dp[n][sum] = min(min_sub_diff_mem(arr, n-1, sum, s1 + arr[n-1]), min_sub_diff_mem(arr, n-1, sum, s1));

}

int min_sub_diff_bottom(int arr[], int n, int sum) {
	bool t[501][501] = {false};
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=sum;j++) {
			if(!i and !j) dp[i][j] = true;
			else if(!i and j) dp[i][j] = false;
			else if(i and !j) dp[i][j] = true;
			else dp[i][j] = dp[i-1][j - arr[i-1]] or dp[i-1][j];
		}
	}
	int res = INT_MAX;
	for(int i=0;i<=sum;i++) {
		if(dp[n][i]) res = min(res, abs(sum - 2*i));
	}
	return res;
}

int main() {
	int n,t;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	int arr[1000];
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	int sum = accumulate(arr, arr + n, 0);
	cout<<min_sub_diff_brute(arr, n, sum, 0)<<endl;
	cout<<min_sub_diff_mem(arr, n, sum, 0)<<endl;
	cout<<min_sub_diff_bottom(arr, n, sum)<<endl;
	return 0;
}