#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000];
bool p[1000][1000];
void is_palindrome(string s) {
    for(int g=0;g<s.length();g++) {
    	for(int i=0, j=g)
    }
}

int min_parts(string s, int i, int j) {
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(is_palindrome(s, i, j)) return 0;
    int ans = INT_MAX;
    for(int k=i;k<j;k++) {
        int t = min_parts(s, i, k) + min_parts(s, k+1, j) + 1;
        ans = min(t, ans);
    }
    return dp[i][j] = ans;
}
int main() {
	string s;
    cin>>s;
    memset(dp, -1, sizeof(dp));
    memset(p, false, sizeof(p));
    is_palindrome(s)
    cout<<min_parts(s, 0, s.length()-1)<<endl;
	return 0;
}

