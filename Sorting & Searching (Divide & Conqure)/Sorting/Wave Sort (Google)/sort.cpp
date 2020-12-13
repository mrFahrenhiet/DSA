#include<iostream>

using namespace std;

void wave_sort(int a[],int n) {
	for(int i=0;i<n;i+=2) {
		int temp;
		if(i>0 && a[i]<a[i-1]) {
			temp = a[i];
			a[i] = a[i-1];
			a[i-1] = temp;
		}
		if(i<n-1 && a[i]<a[i+1]) {
			temp = a[i];
			a[i] = a[i+1];
			a[i+1] = temp;
		}
	}
	for(int i=0;i<n;i++) {
		cout<<a[i]<<' ';
	}
	cout<<endl;
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
    int *a = new int[n];
    for(int i=0;i<n;i++) {
    	cin>>a[i];
    }
    wave_sort(a,n);
	return 0;
}