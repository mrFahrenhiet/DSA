#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
private:
    int findMinIdx(vector<int>& v, int start) {
        int m = v[start], idx = start;
        for(int i=start; i<v.size(); i++) {
            if(m>=v[i]) {
                m = v[i];
                idx = i;
            }
        }
        return idx;
    }
    
    void printArr(vector<int>& v) {
        for(auto num: v) cout<<num<<" ";
        cout<<endl;
        return;
    }

public:
    int findTimeComplexity(vector<int>& v) {
        int cost = 0;
        for(int i=0; i<v.size()-1;i++) {
            int j = this->findMinIdx(v, i);
            cost += j - i + 1;
            reverse(v.begin() + i, v.begin() + j + 1);
        }
        return cost;
    }
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t, itr = 0;
    cin>>t;
    while(t--) {
        itr++;
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++) {
            int no;
            cin>>no;
            v.push_back(no);
        }
        Solution s;
        int tc = s.findTimeComplexity(v);
        cout<<"Case #"<<itr<<": "<<tc<<endl;
    }
    return 0;

}