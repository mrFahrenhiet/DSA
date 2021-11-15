#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Edge {
public:
	int d;
	int w;
	Edge(): d(0), w(0) {}
	Edge(int dest, int wt): d(dest), w(wt) {}
};

bool all_visited(vector<bool>& visited) {
	for(auto v: visited) {
		if(!v) return false;
	}
	return true;
}

bool is_hcyc(int node, vector<vector<Edge>>& graph) {
	for(auto sn: graph[0]) {
		if(node==sn.d) return true;
	}
	return false;
}

void travel(vector<vector<Edge>>& graph, vector<bool>& visited, vector<int>& path, int src) {
	visited[src] = true;
	path.push_back(src);

	if(all_visited(visited)) {
		if(is_hcyc(path.back(), graph)) cout<<"cycle - ";
		else cout<<"path - ";
		for(auto p: path) cout<<p<<" ";
		cout<<endl;
	}

	for(auto nbr: graph[src]) {
		if(!visited[nbr.d]) {
			travel(graph, visited, path, nbr.d);
		}
	}
	visited[src] = false;
	path.pop_back();
	return;
}

void hamiltonian_paths(vector<vector<Edge>>& graph, int e) {
	vector<bool> visited(e, false);
	vector<int> path;
	travel(graph, visited, path, 0);
	return;
}

int main() {
	int e,v;
	cin>>e>>v;
	vector<vector<Edge>> graph;
	for(int i=0;i<e;i++) graph.push_back({});
	for(int i=0;i<v;i++) {
		int source, destination, weight;
		cin>>source>>destination>>weight;
		graph[source].push_back(Edge(destination, weight));
		graph[destination].push_back(Edge(source, weight));
	}
	hamiltonian_paths(graph, e);
	return 0;
}