#include <bits/stdc++.h>
using namespace std;
#define ll long long int


class Solutions {
private:
	int dp[105][105];
public:
	Solutions() {
		memset(dp, -1, sizeof(dp));
	}

	int find_nos_subsets_bottom(int arr[], int sum, int n) {
		int t[105][105];
		memset(t, 0, sizeof(t));
		for(int i=0;i<=n;i++) {
			for(int j=0;j<=sum;j++) {
				if(j==0 or i==0) {
					t[i][j] = 1;
					if(i==0) t[i][j] = 0;
					if(i==0 and j==0) t[i][j] = 1;
				}
				else {
					if(j >= arr[i-1])
						t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j];
					else t[i][j] = t[i-1][j];
				}
			}
		}
		return t[n][sum];
	}

	int find_nos_subsets_mem(int arr[], int sum, int n) {
		if(sum==0) return 1;
		if(n<=0) return 0;
		if(dp[n][sum]!=-1) return dp[n][sum];
		if(sum >= arr[n-1]) return dp[n][sum] = find_nos_subsets_mem(arr, sum - arr[n-1], n-1) + find_nos_subsets_mem(arr, sum, n-1);
		return dp[n][sum] = find_nos_subsets_mem(arr, sum, n-1);
	}

	int find_nos_subsets_brute(int arr[], int sum, int n) {
		if(sum==0) return 1;
		if(n<=0) return 0;
		if(sum >= arr[n-1]) return find_nos_subsets_brute(arr, sum - arr[n-1], n-1) + find_nos_subsets_brute(arr, sum, n-1);
		return find_nos_subsets_brute(arr, sum, n-1);
	}
};




int main() {
	int n, t, diff;
	cin>>t;
	int arr[1000];
	while(t--) {
		memset(arr, 0, sizeof(arr));
		cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
		cin>>diff;
		int sum = accumulate(arr, arr + n, 0);
		int sum_subset = (sum - diff)/2;
		Solutions s;
		cout<<s.find_nos_subsets_brute(arr, sum_subset, n)<<endl;
		cout<<s.find_nos_subsets_mem(arr, sum_subset, n)<<endl;
		cout<<s.find_nos_subsets_bottom(arr, sum_subset, n)<<endl;
	}
	return 0;
}