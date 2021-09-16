#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
// pure recursion
int knapsack_brute(int n, int m_wt, int wt[], int val[]) {
	if(n<=0) return 0;
	if(m_wt >= wt[n-1]) 
		return max(val[n-1] + knapsack_brute(n-1, m_wt - wt[n-1], wt, val),
			knapsack_brute(n-1, m_wt, wt, val));

	return knapsack_brute(n-1, m_wt, wt, val);
}

// recursion with memorization (top down dp)
int knapsack_top_down(int n, int m_wt, int wt[], int val[]) {
	if(n<=0 or m_wt <=0) return 0;
	if(dp[n][m_wt]!= -1) return dp[n][m_wt];
	if(m_wt >= wt[n-1])
		return dp[n][m_wt] = max(val[n-1] + knapsack_top_down(n-1, m_wt - wt[n-1], wt, val),
			knapsack_top_down(n-1, m_wt, wt, val));

	return dp[n][m_wt] = knapsack_top_down(n-1, m_wt, wt, val);
}

int knapsack_bottom_up(int n, int m_wt, int wt[], int val[]) {
	int store[105][105] = {0};
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=m_wt;j++) {
			if(j==0 or i==0) store[i][j] = 0;
			else {
				if(wt[i-1] <= j) store[i][j] = max(val[i-1] + store[i-1][j - wt[i-1]], store[i-1][j]);
				else store[i][j] = store[i-1][j];
			}
		}
	}
	return store[n][m_wt];
}

int knapsack_space_opt(int n, int m_wt, int wt[], int val[]) {
	int t[2][m_wt+1];
	memset(t, 0, sizeof(t));
	for(int i=0;i<n;i++) {
		for(int j=1;j<=m_wt;j++) {
			if(i%2) {
				if(j >= wt[i]) t[0][j] = max(val[i] + t[1][j - wt[i]], t[1][j]);
				else t[0][j] = t[1][j];
			}
			else {
				if(j >= wt[i]) t[1][j] = max(val[i] + t[0][j - wt[i]], t[0][j]);
				else t[1][j] = t[0][j];
			}
		}
	}
	return n%2==0?t[0][m_wt]:t[1][m_wt];
}

int main() {
	int n, m_wt;
	int wt[1000], val[1000];
	cin>>n>>m_wt;
	for(int i=0;i<n;i++) {
		cin>>wt[i]>>val[i];
	}
	memset(dp, -1, sizeof(dp));
	cout<<knapsack_brute(n, m_wt, wt, val)<<endl;
	cout<<knapsack_top_down(n, m_wt, wt, val)<<endl;
	cout<<knapsack_bottom_up(n, m_wt, wt, val)<<endl;
	cout<<knapsack_space_opt(n, m_wt, wt, val)<<endl;
}