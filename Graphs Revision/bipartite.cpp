#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isBipartiteRecUtil(vector<vector<int>>& graph, vector<int>& sets, int src) {
    for(auto nbr: graph[src]) {
        if(sets[nbr]==-1) {
            if(sets[src]==1) sets[nbr] = 0;
            else sets[nbr] = 1;
            if(!isBipartiteRecUtil(graph, sets, nbr)) return false;
        }
        if(sets[nbr]==sets[src]) return false;
    }
    return true;
}

bool isBipartiteRec(vector<vector<int>>& graph) {
    vector<int> sets(graph.size(), -1);
    for(int i=0;i<graph.size();i++) {
        if(sets[i]==-1) {
            sets[i] = 0;
            if(!isBipartiteRecUtil(graph, sets, i)) return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    queue<int> q;
    vector<int> sets(graph.size(), -1);
    for(int i=0;i<graph.size();i++) {
        if(sets[i]==-1) {
            q.push(i);
            sets[i] = 0;
            while(!q.empty()) {
                int temp = q.front();
                q.pop();
                for(auto nbr: graph[temp]) {
                    if(sets[temp]==0) {
                        if(sets[nbr]==-1) {
                            sets[nbr] = 1;
                            q.push(nbr);
                        }
                        if(sets[nbr]==0) return false;
                    }
                    else if(sets[temp]==1) {
                        if(sets[nbr]==-1) {
                            sets[nbr] = 0;
                            q.push(nbr);
                        }
                        if(sets[nbr]==1) return false;
                    }
                }
            }
            while(!q.empty()) q.pop();
        }
    }
    return true;
}

int main() {
	int e,v;
	cin>>e>>v;
	vector<vector<int>> graph;
	for(int i=0;i<e;i++) graph.push_back({});
	for(int i=0;i<v;i++) {
		int source, destination;
		cin>>source>>destination;
		graph[source].push_back(destination);
		graph[destination].push_back(source);
	}
	bool ans = isBipartite(graph);
	cout<<ans;
	return 0;
}