#include<iostream>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	int b[n+1][m+1];
	int **a = new int*[n];
	for(int row=0;row<n;row++) {
		a[row] = new int[m];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++) {
		int y=0;
		for(int j=0;j<m;j++) {
			y+=a[i][j];
			b[i][j] = y;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(i==0) {
				continue;
			}
			b[i][j] += b[i-1][j];
		}
	}
	// for(int i=0;i<n;i++) {
	// 	cout<<endl;
	// 	for(int j=0;j<m;j++) {
	// 		cout<<b[i][j]<<" ";
	// 	}
	// }
	int query[4];
	for(int ele=0;ele<4;ele++) {
		cin>>query[ele];
	}
	int v = b[query[2]][query[3]];
	int p = b[query[2]][query[1]-1];
	int q = b[query[0]-1][query[3]];
	int r = b[query[0]-1][query[1]-1];
	int sum = v-p-q+r;
	cout<<sum<<endl;
    return 0;
}