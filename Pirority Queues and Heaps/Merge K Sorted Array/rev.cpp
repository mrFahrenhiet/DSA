#include<bits/stdc++.h>
using namespace std;
class PairIdxVal {
 public:
    int v;
    int arrIdx;
    int idx;
    PairIdxVal(int v, int arrIdx, int idx): v(v), arrIdx(arrIdx), idx(idx) {}
};
class Comp {
public:
    bool operator()(PairIdxVal& a, PairIdxVal& b) {
        if(a.v == b.v) return a.idx > b.idx;
        return a.v > b.v;
    }
};

vector<int> mergeKArrays(vector<vector<int> > arrays) {
    vector<int> res;
    priority_queue<PairIdxVal, vector<PairIdxVal>, Comp> pq;
    for(int i=0;i<arrays.size();i++) {
        pq.push({arrays[i][0], i, 0});
    }
    while(!pq.empty()) {
        PairIdxVal temp = pq.top();
        pq.pop();
        res.push_back(temp.v);
        if(temp.idx < arrays[temp.arrIdx].size()-1) pq.push({arrays[temp.arrIdx][temp.idx+1], temp.arrIdx, temp.idx+1});
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int k;
    cin>>k;
    vector<vector<int>> arr;
    while(k--) {
        int n;
        
    }

    return 0;

}