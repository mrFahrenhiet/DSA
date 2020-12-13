/* 
SANKET AND STRINGS
Sanket has a string consisting of only 'a' and 'b' as the characters. Sanket describes perfectness of a string as the maximum length substring of equal characters. Sanket is given a number k which denotes the maximum number of characters he can change. Find the maximum perfectness he can generate by changing no more than k characters.

Input Format:
The first line contains an integer denoting the value of K. The next line contains a string having only ‘a’ and ‘b’ as the characters.

Constraints:
2 ≤ N ≤ 10^5

Output Format
A single integer denoting the maximum perfectness achievable.

Sample Input
2
abba
Sample Output
4
*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// ll dp[1000][1000];
ll find_max_len(string s,ll n,ll k) { 
  if(n<=0) {
    return 1;
  }
  ll d=0,e=0,f=0;
  if(s[n]==s[n-1]) {
    d =  find_max_len(s,n-1,k)+2;
  }
  else {
    if(k>0) {
      // s[n-1] = s[n];
      e =  find_max_len(s,n-1,k-1)+2;
    }
    f = find_max_len(s,n-1,k);
  }
  return max(d,max(e,f));
}


int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
string s;
  ll k,max=0;
  cin>>k;
  cin>>s;
  // char ch='a';
  // char *i = &s[0];
  // char *j = &s[1];
  // while(*i!='\0' && *j!='\0') {
  //   if(*i==*j){
  //     j++;
  //     m++;
  //     count++;
  //     if(max<=count){
  //       max=count+1;
  //       ll=l;
  //       mm=m;
  //       ch = *i;
  //     }
  //   }
  //   else {
  //     i++;
  //     j++;
  //     l++;
  //     m++;
  //     count=0;
  //   }
  // }
  // // cout<<max<<"\t"<<ll<<"-"<<mm<<"\t"<<ch;
  // ll x =0;
  // for(ll p=0;p<s.size();p++) {
  //   if(s[p]!=ch) {
  //     s[p]=ch;
  //     x++;
  //     if(x>=k) {
  //       break;
  //     }
  //   }
  //   // cout<<"\n"<<s[p];
  // }
  // memset(dp,-1,sizeof dp);
  if(k>=s.size()) {
    cout<<s.size();
  }
  else {
    ll max_sub = find_max_len(s,s.size(),k);
    cout<<max_sub;
  }
  return 0;
}