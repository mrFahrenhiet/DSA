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
		map<T,int> dist;
		queue<T> q;

		for(auto n_p:l) {
			T n = n_p.first;
			dist[n] = INT_MAX;
			// list<T> n2 = n_p.second;
			// for(auto ij: n2) {
			// 	dist[ij] = INT_MAX;
			// }
			// dist[n] = INT_MAX;
		}
		q.push(src);
		dist[src] = 0;

		while(!q.empty()) {
			T node = q.front();
			q.pop();

			for(auto nbr:l[node]) {
				if(dist[nbr]==INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[node]+6;
				}
			}
		}

		for(auto it: l) {
			T node = it.first;
			int d = dist[node];
			cout<<node<<"-"<<"Dist="<<d<<endl;
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
    g.addEdge(1,2);
    g.addEdge(3,1);
    g.bfs(1);
    return 0;

}