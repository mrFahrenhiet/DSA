
#include<iostream>
#include<cmath>
using namespace std;

void rotate(int a[][50],int n) {
    int x;
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            x = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = x;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n/2;j++) {
            int y = a[i][j];
            a[i][j] = a[i][n-1-j];
            a[i][n-1-j] = y;

        }
    }
    for(int i=0;i<n;i++) {
        cout<<endl;
        for(int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
    }
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    int n,a[50][50],x;
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    rotate(a,n);
	return 0;

}