#include <iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
void find_median(vector<int> &a) {
    priority_queue <int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    int m= INT_MAX;
    for(int i=0;i<a.size();i++) {
        if(a[i]<m) { 
            q1.push(a[i]);
        }
        else if(a[i]>m) {
            q2.push(a[i]);
        }
        if(q1.size()>q2.size()+1) {
            int x = q1.top();
            q1.pop();
            q2.push(x);
        }
        else if(q2.size()>q1.size()+1) {
            int x = q2.top();
            q2.pop();
            q1.push(x); 
        }
        if(q1.size()>q2.size()) {
            m = q1.top();
            cout<<m<<" ";
        }
        else if(q1.size()<q2.size()) {
            m  = q2.top();
            cout<<m<<" ";
        }
        else {
            m = (q1.top()+q2.top())/2;
            cout<<m<<" ";
        }
    }
    return;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int test;
    cin>>test;
    for(int c=0;c<test;c++) {
        vector<int> v;
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            int no;
            cin>>no;
            v.push_back(no);
        }
        find_median(v);
    }
    return 0;
}

