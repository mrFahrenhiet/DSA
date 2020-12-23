#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void increaseTemp(vector<int> &v) {
    stack<int> s;
    vector<int> res(v.size(),0);
    for(int i=0;i<v.size();i++) {
        while(!s.empty() and v[i]>v[s.top()]) {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    for(auto r: res) cout<<r<<" ";
    cout<<endl;
    return;
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
    increaseTemp(v);
    return 0;

}