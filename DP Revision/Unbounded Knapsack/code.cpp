#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int unbounded_brute(int wt[], int val[], int n, int m_wt) {
	if(!n) return 0;
	if(m_wt >= wt[n-1]) return max(val[n-1] + unbounded_brute(wt, val, n, m_wt - wt[n-1]), unbounded_brute(wt, val, n-1, m_wt));
	return unbounded_brute(wt, val, n-1, m_wt);
}

int unbounded_bottom(int arr[], int)

int main() {
	int n,t;
	int wt[1000], val[1000];
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>arr[i];
	}
	int m_wt;
	cin>>m_wt;
	cout<<unbounded_brute(arr, n, m_wt)<<endl;
	return 0;
}