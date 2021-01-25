#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

//Top Down Rec + Mem
vector<int> dp_top(1005,0);
int min_coins_top(int n,int a[],int size) {
	if(n==0) {
		return 0;
	}
	if(n<0) return -1;
	if(dp_top[n]!=0) {
		return dp_top[n];
	}
	int ans = INT_MAX;
	int subprob = INT_MAX;
	for(int i=0;i<size;i++) {
		subprob = min_coins_top(n-a[i],a,size)+1;
		ans = min(ans,subprob);	
	}
	return dp_top[n] = ans;
}
//bottom up
int min_coins_bottom(int n,int a[],int size) {
	vector<int> dp_bottom(size,n+5);
	dp_bottom[0] = 0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<size;j++) {
			if(i-a[j]>=0) {
				dp_bottom[i] = min(dp_bottom[i],dp_bottom[i-a[j]]+1);
			}
		}
	}
	return dp_bottom[n];
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int coins[] = {1,2,5};
    int s = sizeof(coins)/sizeof(int);

    int n;
    cin>>n;
    cout<<min_coins_bottom(n,coins,s);
    return 0;

}