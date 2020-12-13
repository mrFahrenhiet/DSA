#include<bits/stdc++.h>
using namespace std;

int min_cost_join_ropes(int a[],int n) {
	priority_queue<int, vector<int>, greater<int>> pq(a,a+n);
	int cost = 0;
	while(pq.size()>1) {
		int f = pq.top();
		pq.pop();
		int s = pq.top();
		pq.pop();
		cost+=(f+s);
		pq.push((f+s));
	}
	return cost;
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
    for(int k=0;k<n;k++) {
    	int no;
    	cin>>no;
    	a[k] = no;
    }
    cout<<min_cost_join_ropes(a,n);

    return 0;

}