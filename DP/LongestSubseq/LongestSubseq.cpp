#include <bits/stdc++.h>
using namespace std;

// brute force dp
int longest_subseq(int a[],int n) {
    int maxlen=1,blen,maxi;
    vector<int> len(n,1);
    for(int i=0;i<n;i++) {
        maxi = 1;
        for(int j=i;j>=0;j--) {
            if(a[j]<a[i]) {
                blen = maxi+len[j];
                len[i] = max(len[i],blen);
            }
        }
        maxlen = max(len[i],maxlen);
    }
    return maxlen;
}

// Slightly Better almost same
vector<int> dp(100,INT_MAX);
int lis(vector<int> &v) {
    dp[0] = INT_MIN;
    for(int i=0;i<v.size();i++) {
        for(int j=0;j<v.size();j++) {
            if(dp[j]<v[i] &&  v[i]<dp[j+1]) {
                dp[j+1] = v[i];
            }
        }
    }
    int ans;
    for(int l=1;l<=v.size();l++) {
        if(dp[l]!=INT_MAX)
            ans = l;
    }
    return ans;

}

// Better TC = O(nlogn)
int lis_better(vector<int> &v) {
    dp[0] = INT_MIN;
    for(int i=0;i<v.size();i++) {
        int s = 0, e = v.size()-1;
        int temp;
        while(s<=e) {
            int m = (s+e)/2;
            if(v[i]>=dp[m]) {
                temp = m;
                s = m + 1;
            }
            else {
                e = m - 1;
            }
        }
        if(v[i]>dp[temp] and v[i]<dp[temp+1]) {
            dp[temp+1] = v[i];
        }
    }
    int ans = INT_MIN;
    for(int i=0;i<v.size();i++) {
        if(dp[i]!=INT_MAX) {
            ans = i;
        }
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        a.push_back(no);
    }
    cout<<lis_better(a);
}
