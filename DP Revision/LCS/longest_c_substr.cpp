#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[105][105];
int res = 0;
unordered_map<string, int> dp2;

int lcsubstr_recursive(string s1, string s2, int n1, int n2, int mxlen) {
	if(!n1 or !n2) {
		res = max(res, mxlen);
		return mxlen;
	}
	if(s1[n1-1] == s2[n2-1])
		return lcsubstr_recursive(s1, s2, n1-1, n2-1, mxlen + 1);
	else {
		res = max(res, mxlen);
		return max(lcsubstr_recursive(s1, s2, n1-1, n2, 0), lcsubstr_recursive(s1, s2, n1, n2-1, 0));
	}
}

// mem_with_space_optimzation
int lcsubstr_mem(string s1, string s2, int n, int m, int count) {
	if(n==0 or m==0) return count;
	if(dp2.count(to_string(n)+to_string(m)+to_string(count))) return dp2[to_string(n)+to_string(m)+to_string(count)];
	int eq = count;
	if(s1[n-1]==s2[m-1]) eq = lcsubstr_mem(s1, s2, n-1, m-1, count+1);
	int res = max({eq, lcsubstr_mem(s1, s2, n-1, m, count), lcsubstr_mem(s1, s2, n, m-1, count)});
	return dp2[to_string(n)+to_string(m)+to_string(count)] = res;
}

int lcsubstr_itr(string s1, string s2) {
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<=s1.length();i++) {
		for(int j=0;j<=s2.length();j++) {
			if(i==0 or j==0) dp[i][j] = 0;
			else if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = 0;
		}
	}

	int res = 0;
	for(int i=0;i<=s1.length();i++) {
		for(int j=0;j<=s2.length();j++) res = max(res, dp[i][j]);
	}

	return res;
}

int main() {
	string s1, s2;
	cin>>s1>>s2;
	memset(dp, -1, sizeof(dp));
	int lcs_r = lcsubstr_recursive(s1, s2, s1.length(), s2.length(), 0);
	int lcs_i = lcsubstr_itr(s1, s2);
	int lcs_m = lcsubstr_mem(s1, s2, s1.length(), s2.length(), 0);
	cout<<lcs_r<<endl;
	cout<<lcs_i<<endl;
	cout<<lcs_m<<endl;
	return 0;
}