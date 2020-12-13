#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T>
class Graph {
	unordered_map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		// l[y].push_back(x);
	}
	bool cycHelp(T src, map<T,bool> &visited, map<T,T> &parent) {
		visited[src] = true;
		for(auto nbr: l[src]) {
			if(visited[nbr]==true && parent[src]!=nbr) {
				return true;
			}
			else if(visited[nbr]==false) {
				parent[nbr] = src;
				bool cyc = dfsHelp(nbr,visited,parent);
				if(cyc==true) {
					return true;
				}
			}
		}
		return false;
	}
	void findcyc(T src) {
		map<T,bool> visited;
		map<T,T> parent;
		for(auto itr:l) {
			T node = itr.first;
			visited[node] = false;
		}
		parent[src] = src;
		cout<<cycHelp(src,visited,parent);
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
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.findcyc(0);
    return 0;

}