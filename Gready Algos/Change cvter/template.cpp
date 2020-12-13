#include<iostream>
#include<algorithm>
using namespace std;

int min_coins(int n,int a[],int size) {
	int ans = 0,count=0;
	int e = size-1;
	int s = 0;
	while(n>0) {
		while(s<=e) {
			int m = (s+e)/2;
			if(a[m]>n) {
				e = m-1;
			}
			else {
				ans = a[m];
				s = m+1;
			}
		}
		n -= ans;
		count++;
		s = 0;
		e = size;
	}
	return count;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int coins[] = {1,5,7};
    int s = sizeof(coins)/sizeof(int);
    int n;
    cin>>n;
    cout<<min_coins(n,coins,s);
    return 0;

}