#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1001][1001][2];
int evaluate(string s, int i, int j, bool is_true) {
	if(i>j) return false;
	if(i==j) {
		if(is_true) return s[i] == 'T';
		else return s[i] == 'F';
	}
	if(dp[i][j][is_true]!=-1) return dp[i][j][is_true];
	int ans = 0;
	for(int k=i+1;k<j;k+=2) {
		int lf_t = evaluate(s, i, k-1, true);
		int lf_f = evaluate(s, i, k-1, false);
		int rt_t = evaluate(s, k+1, j, true);
		int rt_f = evaluate(s, k+1, j, false);
		if(s[k]=='&') {
			if(is_true) ans += lf_t * rt_t; 
			else ans += lf_f*rt_t + lf_t*rt_f + lf_f*rt_f;
		}
		else if(s[k]=='|') {
			if(is_true) ans += lf_t * rt_t + lf_f*rt_t + lf_t*rt_f; 
			else ans += lf_f*rt_f;
		}
		else if(s[k]=='^') {
			if(is_true) ans += lf_f*rt_t + lf_t*rt_f; 
			else ans += lf_t * rt_t + lf_f*rt_f;
		}
	}
	return dp[i][j][is_true] = ans;
}
int main() {
	string s;
	cin>>s;
	memset(dp, -1, sizeof(dp));
	cout<<evaluate(s, 0, s.size()-1, true);
	return 0;
}