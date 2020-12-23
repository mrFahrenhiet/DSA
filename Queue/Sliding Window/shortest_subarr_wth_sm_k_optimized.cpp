#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int shortestSubarr(vector<int> &v, int k) {
    int res = INT_MAX;
    deque<int> dq;
    for(int i=0;i<v.size();i++) {
        if(i>0) v[i] += v[i-1];
        if(v[i]>=k) res = min(res, i+1);
        while(!dq.empty() and v[i]-v[dq.front()]>=k) {
            res = min(res, i-dq.front());
            dq.pop_front();
        }
        while(!dq.empty() and v[i]<v[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    return res==INT_MAX?res:-1;
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
    vector<int> v;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        v.push_back(no);
    }
    int k;
    cin>>k;
    int x = shortestSubarr(v, k);
    cout<<x<<endl;
    return 0;

}