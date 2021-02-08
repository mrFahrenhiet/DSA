#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int lastB(vector<int>& v, int n, int k) {
    while(k>0) {
        bool f = false;
        for(int i=0;i<n-1;i++) {
            if(v[i]<v[i+1]) {
                f = true;
                if(k-(v[i+1]-v[i])>0) {
                    k -= (v[i+1]-v[i]);
                    v[i] += (v[i+1]-v[i]);
                }
                else if(k-(v[i+1]-v[i])<=0) {
                    return i+1>=v.size()?-1:i+1;
                }
            }
        }
        if(!f and k>=0) return -1;
    }
    return -1;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    vector<int> v;
    while(t--) {
        int n, k;
        cin>>n>>k;
        for(int i=0;i<n;i++) {
            int no;
            cin>>no;
            v.push_back(no);
        }
        cout<<lastB(v, n, k)<<endl;
        v.clear();
    }
    return 0;

}