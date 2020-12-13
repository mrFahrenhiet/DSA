#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> p1,pair<int,int> p2) {
    return p1.second<p2.second;
}
int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) {
        int c,r;
        cin>>c>>r;
        v.push_back(make_pair(c-r,c+r));
    }
    // sort(v.begin(),v.end(),comp);
    int i=0,j=i+1,cnt=1;
    while(i<n && j<n) {
        if(v[i].second>v[j].first) {
            j++;
        }
        else {
            cnt++;
            i=j;
            j++;
        }
    }
    cout<<n-cnt<<endl;
}
