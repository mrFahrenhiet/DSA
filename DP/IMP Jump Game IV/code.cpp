#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int maxResult(vector<int> &v, int k) {
	deque<int> dq;
	ll sum = 0;
	for(int i=v.size()-1; i>=0; i--) {
		sum = v[i] + (dq.empty()?0:v[dq.front()]);
		while(!dq.empty() and sum>v[dq.back()]) dq.pop_back();
		dq.push_back(i);
		if(!dq.empty() and dq.front()>=i+k) dq.pop_front();
		v[i] = sum;
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
    int n, k;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++) {
    	int no;
    	cin>>no;
    	v.push_back(no);
    }
    cin>>k;
    int x = maxResult(v, k);
    cout<<x<<endl;
    return 0;

}