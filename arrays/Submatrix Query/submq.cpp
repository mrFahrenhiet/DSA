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
	int **a = new int*[n];
	for(int row=0;row<n;row++) {
		a[row] = new int[m];
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	int query[4];
	for(int ele=0;ele<4;ele++) {
		cin>>query[ele];
	}
	int sum = 0;
	for(int i=query[0];i<=query[2];i++) {
		for(int j = query[1];j<=query[3];j++) {
			sum+=a[i][j];
		}
	}
	cout<<sum<<endl;
    return 0;
}