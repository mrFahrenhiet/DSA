#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T>
class Graph {
	unordered_map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}
	void dfsHelp(T src, map<T,bool> &visited) {
		cout<<src<<" ";
		visited[src] = true;
		for(auto nbr: l[src]) {
			if(visited[nbr]==false) {
				dfsHelp(nbr,visited);
			}
		}
		return;
	}
	void dfs(T src) {
		map<T,bool> visited;
		for(auto itr:l) {
			T node = itr.first;
			visited[node] = false;
		}
		dfsHelp(src,visited);
		return;
	}

};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs(0);
    return 0;

}