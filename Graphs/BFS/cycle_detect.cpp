#include <bits/stdc++.h>
using namespace std;
class Graph {
    list<int> *l;
    int V;
public:
    Graph(int v) {
        this->V = v;
        l = new list<int>[v];
    }

    void addEdge(int x,int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool is_tree(int src) {
        map<int,bool> visited;
        map<int,int> parents;
        queue<int> q;
        for(int it=0;it<V;it++) {
            visited[it] = false;
            parents[it] = it;
        }
        visited[src] = true;
        parents[src] = src;
        q.push(src);
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            for(auto itr:l[n]) {
                if(visited[itr]==true && parents[n]!=itr) {
                    return false;
                }
                if(visited[itr]==false) {
                    visited[itr] = true;
                    parents[itr] = n;
                    q.push(itr);
                }
            }
        }
        return true;
    }

};

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Graph g(6);
    g.addEdge(0,1);
    // g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    cout<<g.is_tree(0);
}
