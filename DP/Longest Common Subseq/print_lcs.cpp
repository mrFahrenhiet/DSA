#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

void print_lcs(string &x, string &y) {
    int maxlen = lcs_imp(x,y);
    vector<char> v;
    int i = x.size();
    int j = y.size();
    while(i>0 && j>0) {
        if(dp[i][j]>dp[i-1][j-1] && dp[i][j]>dp[i-1][j] 
            && dp[i][j]>dp[i][j-1]) {
                v.push_back(x[i-1]);
                i-=1;
                j-=1;
        }
        else if(dp[i][j]>=dp[i-1][j-1] && dp[i][j]==dp[i-1][j]) {
                i-=1;
        }
        else if(dp[i][j]>=dp[i-1][j-1] && dp[i][j]==dp[i][j-1]) {
                j-=1;
        }
        else if(dp[i][j]<=0) {
            break;
        }
    }
    reverse(v.begin(),v.end());
    for(auto it:v) {
        cout<<it;
    }
    return;
}

int main() {
    string x,y;
    cin>>x>>y;
    lcs(x,y);

}
