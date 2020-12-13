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
	void dfs() {
		map<T,bool> visited;
		int cnt = 0;
		for(auto src:l) {
			T node = src.first;
			if(!visited[node]) {
				cout<<"Componet "<<cnt<<"->";
				dfsHelp(node,visited);
				cout<<endl;
				cnt++;
			}
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
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);
    
    g.addEdge(5,6);
    g.addEdge(6,7);

    g.addEdge(8,8);
    
    g.dfs();
    return 0;

}