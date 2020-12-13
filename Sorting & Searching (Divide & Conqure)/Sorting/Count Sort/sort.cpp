#include<iostream>
#include<vector>
using namespace std;

void count_sort(int a[], int n) {
	vector<int> freq(20,0);
	int maxi;
	for(int i=0;i<n-1;i++) {
		maxi = max(a[i],a[i+1]);
	}
	for(int i=0;i<maxi;i++) {
		freq[a[i]]++;
	}
	int new_arr[n];
	for(int i=0;i<=n;i++) {
		while(freq[i]>0) {
			cout<<i<<" ";
			freq[i]--;
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
    int *a = new int[n];
    for(int i=0;i<n;i++) {
    	cin>>a[i];
    }
    count_sort(a,n);
	return 0;
}