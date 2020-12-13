#include<bits/stdc++.h> 
using namespace std;
bool comp(const pair<string , int> &a, const pair<string , int> &b) {
    if(a.second==b.second) {
        return a.first<b.first;
    }
    return a.second>b.second;
}
int main() {
    int min;
    int n;
    cin>>min>>n;
    pair<string,int>p[n];
    for(int i=0;i<n;i++) {
        string name;
        int sal;
        cin>>name>>sal;
        p[i].first = name;
        p[i].second = sal;
    }
    sort(p,p+n,comp);
    for(int i=0;i<n;i++) {
        if(p[i].second>min) {
            cout<<p[i].first<<" "<<p[i].second<<endl;
        }
    }

	return 0;
}