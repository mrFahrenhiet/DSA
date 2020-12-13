#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int maxAreaRect(int mat[100][100], int m, int n) {
	int hist[n][m];
	for(int i=0;i<m;i++) {
		hist[0][i] = mat[0][i];
		for(int j=1;j<n;j++) {
			hist[j][i] =  (mat[j][i] == 0) ? 0 : hist[j-1][i] + 1;
		}
	}
    int res = 0;
	for(int i=0;i<n;i++) {
        int arr[n+1],cnt=0;
        memset(arr,0,sizeof arr);
    	for(int j=0;j<m;j++) {
    		arr[hist[i][j]]++;
    	}
    	for(int j=n;j>=0;j--) {
            cnt += arr[j];
            // cout<<j<<" "<<cnt<<endl;
            res = max(res,cnt*j);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<hist[i][j]<<" ";
        }
        cout<<endl;
    }
    return res;
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
    int mat[100][100];
    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		cin>>mat[i][j];
    	}
    }
    int x = maxAreaRect(mat,m,n);
    cout<<x<<endl;
    return 0;

}