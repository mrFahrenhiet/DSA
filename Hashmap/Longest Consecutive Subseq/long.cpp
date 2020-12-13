#include <bits/stdc++.h>
using namespace std;
int long_seq(vector<int> &A) {
    map<int,int> m;
    for(auto itr: A) {
        if(m.count(itr)>0)
            m[itr]++;
        else
            m[itr] = 1;
    }
    int ans = 0;
    int cnt = 0;
    for(int j=0;j<m.size();j++) {
        if(m.count(A[j]-1)>0) {
            continue;
        }
        else {
            int x = A[j];
            while(m.count(x)>0) {
                cnt+=m[x];
                x++;
            }
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    return ans;
}
int longest_subseq_base(vector<int> &a) {
    set<int> s;
    for(int i=0;i<a.size();i++) {
        s.insert(a[i]);
    }
    int min = *s.begin();
    int maxi = *s.rbegin();
    int cnt = 0,ans = 0;
    for(int i=min;i<maxi;i++) {
        if(s.count(i)==1) {
            cnt++;
        }
        else {
            ans = max(ans,cnt);
            cnt = 0;
        }
    }
    return ans; 

}
int main() {
    int n;
    vector<int> v;
    cin>>n;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        v.push_back(no);
    }
    cout<<longest_subseq_base(v);
}
