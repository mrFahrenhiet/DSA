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
	for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		cout<<hist[i][j]<<" ";
    	}
    	cout<<endl;
    }
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
    return 0;

}