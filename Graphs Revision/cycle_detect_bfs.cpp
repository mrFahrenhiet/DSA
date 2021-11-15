#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Edge {
public:
	int d;
	int w;
	Edge(): d(0), w(0) {}
	Edge(int nbr, int wt): d(nbr), w(wt) {}
};
bool bfs_check(unordered_map<int,vector<Edge>>& graph, vector<bool>& visited, int src) {
	queue<int> q;
	q.push(src);
	while(!q.empty()) {
		int temp = q.front();
		q.pop();
		if(visited[temp]) return true;
		else visited[temp] = true;
		for(auto nbr: graph[temp]) {
			if(!visited[nbr.d]) q.push(nbr.d);
		}
	}
	return false;
}
bool cycle_detect(unordered_map<int,vector<Edge>>& graph, int e) {
	vector<bool> visited(e, false);
	bool f = false;
	for(int i=0;i<e;i++) {
		if(!visited[i]) f = bfs_check(graph, visited, i);
		if(f) {
			cout<<i<<endl;
			return true;
		}
	}
	return false;
}
int main() {
	int v, e;
	cin>>e>>v;
	unordered_map<int, vector<Edge>> graph;
	for(int i=0;i<v;i++) {
		int s, nb, wt;
		cin>>s>>nb>>wt;
		graph[s].push_back(Edge(nb, wt));
		graph[nb].push_back(Edge(s, wt));
	}
	bool ans = cycle_detect(graph, e);
	cout<<ans<<endl;
	return 0;
}