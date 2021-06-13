#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Cabs {
public:
    string s;
    int x;
    int y;
    Cabs(int x, int y, string s): x(x), y(y), s(s) {}
    int dist() {
        return x*x + y*y;
    }
};
class Comp {
public:
    bool operator()(Cabs& c1, Cabs& c2) {
        return c1.dist() < c2.dist();
    }
};

void getKthClosests(vector<Cabs>& v, int k) {
    int i = 0;
    priority_queue<Cabs, vector<Cabs>, Comp> pq;
    for(i=0;i<k;i++) pq.push(v[i]);
    for(;i<v.size();i++) {
        Cabs top = pq.top();
        if(top.dist()>v[i].dist()) {
            pq.pop();
            pq.push(v[i]);
        }
    }
    vector<Cabs> res;
    while(!pq.empty()) {
        Cabs top = pq.top();
        res.push_back(top);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    for(auto r: res) {
        cout<<r.s<<": "<<r.x<<" "<<r.y<<endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n, k, i = 0;
    cin>>n>>k;
    vector<Cabs> v;
    while(n--) {
        int x, y;
        string s;
        cin>>x>>y>>s;
        Cabs c(x, y, s);
        v.push_back(c);
    }
    getKthClosests(v, k);
    return 0;

}