#include <iostream>
#include <string>
#include <vector>
using namespace std;
//brute force
int longest_subseq(string &x, string &y,int i,int j) {
    if(x[i]=='\0' || y[j]=='\0') {
        return 0;
    }
    if(x[i]==y[j]) {
        return longest_subseq(x,y,i+1,j+1)+1;
    }
    else {
        return max(longest_subseq(x,y,i,j+1),longest_subseq(x,y,i+1,j));
    }
}

//bottom up dp
vector<vector<int> > dp(1000,vector<int>(1000,0));
int lcs_imp(string &x,string &y) {
    for(int i=1;i<=x.size();i++) {
        for(int j=1;j<=y.size();j++) {
            if(x[i-1]==y[j-1]) {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[x.size()][y.size()];
}

int main() {
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1,s2);
}
