#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[105][105];


int lcs_recursive(string s1, string s2, int n1, int n2) {
	if(!n1 or !n2) return 0;
	if(s1[n1-1] == s2[n2-1])
		return 1 + lcs_recursive(s1, s2, n1-1, n2-1);
	return max(lcs_recursive(s1, s2, n1-1, n2), lcs_recursive(s1, s2, n1, n2-1));
}

int lcs_memorize(string s1, string s2, int n1, int n2) {
	if(!n1 or !n2) return 0;
	if(dp[n1][n2]!=-1) return dp[n1][n2];
	if(s1[n1-1] == s2[n2-1])
		return dp[n1][n2] = 1 + lcs_recursive(s1, s2, n1-1, n2-1);
	return dp[n1][n2] = max(lcs_recursive(s1, s2, n1-1, n2), lcs_recursive(s1, s2, n1, n2-1));
}

int lcs_itr(string s1, string s2) {
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=s1.length();i++) {
		for(int j=0;j<=s2.length();j++) {
			if(i==0 or j==0) dp[i][j] = 0;
			else if(s1[i]==s2[j]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[s1.length()][s2.length()];
}

int main() {
	string s1, s2;
	cin>>s1>>s2;
	int lcs_r = lcs_recursive(s1, s2, s1.length(), s2.length());
	memset(dp, -1, sizeof(dp));
	int lcs_m = lcs_memorize(s1, s2, s1.length(), s2.length());
	int lcs_i = lcs_itr(s1, s2);
	cout<<lcs_r<<endl;
	cout<<lcs_m<<endl;
	cout<<lcs_i<<endl;
	return 0;
}