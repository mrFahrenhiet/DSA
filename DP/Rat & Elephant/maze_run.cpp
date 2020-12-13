#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//bottom up
int mazerunele(char a[100][100],int dp[100][100],int m,int n) {
    if(a[0][0]=='X') {
        return 0;
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(a[i][j]=='X') {
                dp[i][j] = 0;
            }
            else if(i==0 and j==0) {
                dp[0][0] = 1;
            } 
            else if(i==0) {
                int sumup =0;
                for(int k=0;k<=j-1;k++) {
                    sumup+=dp[0][k];
                }
                dp[0][j] = sumup; 
            }
            else if(j==0) {
                int sumleft =0;
                for(int k=0;k<=i-1;k++) {
                    sumleft+=dp[k][0];
                }
                dp[i][0] = sumleft;
            }
            else {
                int sumup =0;
                for(int k=0;k<=j-1;k++) {
                    sumup+=dp[i][k];
                }
                int sumleft =0;
                for(int k=0;k<=i-1;k++) {
                    sumleft+=dp[k][j];
                }
                dp[i][j] = sumleft + sumup;
            }
        }
    }
    return dp[m-1][n-1];
}
int mazerunmouse(char a[100][100],int dp[100][100],int m,int n) {
    if(a[0][0]=='X') {
        return 0;
    }
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(a[i][j]=='X') {
                dp[i][j] = 0;
            }
            else if(i==0 and j==0) {
                dp[0][0] = 1;
            } 
            else if(i==0) {
                dp[0][j] = 1;
            }
            else if(j==0) {
                dp[i][0] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}
int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int m,n;
    cin>>m>>n;
    char a[100][100];
    int dp[100][100] = {0};
    for(int r=0;r<m;r++) {
        for(int c=0;c<n;c++) {
            cin>>a[r][c];
        }
    }
    cout<<mazerunele(a,dp,m,n); 
}
