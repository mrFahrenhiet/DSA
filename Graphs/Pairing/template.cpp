#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Graph {
    int V;
    list<pair<int,int> > l;

public:
    Graph(int v) {
        this->V = v; 
    }
    void add_edge(int x, int y) {
        l.push_back(make_pair(x,y));
    }

    int find(int i, vector<int> &parent) {
        if(parent[i]==-1) {
            return i;
        }
        return parent[i] = find(parent[i],parent);
    }

    void union_set(int x, int y, vector<int> &parent, vector<int> &rank) {
        int s1 = find(x,parent);
        int s2 = find(y,parent);

        if(s1!=s2) {
            if(rank[s2]>rank[s1]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }

    int citi_travel() {
        vector<int> parent(V+1,-1);
        vector<int> rank(V+1,1);
        for(auto itr:l) {
            int s1 = find(itr.first,parent);
            int s2 = find(itr.second,parent);
            union_set(s1,s2,parent,rank);
        }
        int ans = 0;
        for(int i=0;i<V;i++) {
            // cout<<i<<" "<<rank[find(i,parent)]<<endl;
            ans+= V-rank[find(i,parent)];
        }
        return ans/2;
    }

};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    Graph g(n);

    while(m--) {
        int x,y;
        cin>>x>>y;
        g.add_edge(x,y);
    }
    cout<<g.citi_travel()<<endl;
    return 0;

}