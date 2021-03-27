#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T>
class Graph {
	map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
	}
	void dfsHelp(T src, map<T,bool> &visited,vector<T> &ordering) {
		visited[src] = true;
		for(auto nbr: l[src]) {
			if(visited[nbr]==false) {
				dfsHelp(nbr,visited,ordering);
			}
		}
		ordering.push_back(src);
		return;
	}
	void dfs() {
		map<T,bool> visited;
		vector<T> ordering;
		for(auto src:l) {
			T node = src.first;
			if(!visited[node]) {
				dfsHelp(node,visited,ordering);
			}
		}
		reverse(ordering.begin(),ordering.end());
		for(auto itr:ordering) {
			cout<<itr<<endl;
		}
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
    g.addEdge(1, 0);
    g.addEdge(0, 1)
    g.dfs();
    return 0;

}