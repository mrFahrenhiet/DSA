#include<iostream>
using namespace std;

int piv(int a[],int s,int e) {
	if(s>e) {
		return -1;
	}
	int m = (s+e)/2;
	
	if(a[m]<a[m-1]) {
		return m-1;
	}
	else if(a[m]>a[m+1]) {
		return m;
	}
	else {
		if(a[m]<=a[s]) {
			piv(a,s,m-1);
		}
		else if(a[m]>=a[e]) {
			piv(a,m+1,e);
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
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int pos = piv(a,0,n-1);
	cout<<pos;
	return 0;
}