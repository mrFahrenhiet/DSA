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
    int findTimeComplexity(vector<int> v) {
        int cost = 0;
        for(int i=0; i<v.size()-1;i++) {
            int j = this->findMinIdx(v, i);
            cost += j - i + 1;
            reverse(v.begin() + i, v.begin() + j + 1);
        }
        return cost;
    }

    vector<int> findArrWithCost(int n, int c) {
        int maxC = n*(n+1)/2 - 1;
        int minC = n-1;
        vector<int> arr;
        if(maxC < c or c < minC) return arr;

        for(int i=1; i<=n; i++) {
            arr.push_back(i);
        }

        if(c==minC) return arr;
        else if(c==maxC) {
            arr.clear();
            for(int i=2;i<=n;i+=2) arr.push_back(i);
            if(n%2==0) {
                for(int i=n-1;i>=0;i-=2) arr.push_back(i); 
            }
            else {
                for(int i=n;i>=0;i-=2) arr.push_back(i); 
            }
            return arr;
        }
        while(next_permutation(arr.begin(), arr.end())) {
            int cost = this->findTimeComplexity(arr);
            if(cost==c) return arr;
        }
        return arr;
    }
};
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t, idx = 0;
    cin>>t;
    while(t--) {
        idx++;
        int n,c;
        cin>>n>>c;
        Solution sol;
        vector<int> res = sol.findArrWithCost(n,c);
        if(!res.size()) cout<<"Case #"<<idx<<": IMPOSSIBLE";
        else {
            cout<<"Case #"<<idx<<": ";
            for(auto num: res) cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;

}