#include<iostream>
#include<cmath>
using namespace std;

int sumgenerator(int **a,int n,int m) {
	int sum = 0;
	int x,y;
	for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		x = (i+1)*(j+1);
    		y = (n-i)*(m-j);
    		sum+=(x*y)*a[i][j];
    	}
    }
    return sum;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
    int n,m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i=0;i<n;i++) {
    	arr[i] = new int[m];

    }
    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		cin>>arr[i][j];
    	}
    }

    int s = sumgenerator(arr,n,m);
    cout<<s<<"\n";

	return 0;
}