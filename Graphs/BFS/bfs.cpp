#include <bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T>
class Graph {
	map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src) {
		map<T,bool> visted;
		queue<T> q;

		q.push(src);
		visted[src] = true;

		while(!q.empty()) {
			T node = q.front();
			cout<<node<<" ";
			q.pop();

			for(auto nbr:l[node]) {
				if(!visted[nbr]) {
					q.push(nbr);
					visted[nbr] = true;
				}
			}
		}
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
    g.bfs(1);
    return 0;

}