#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Edges {
public:
	int nbr;
	int wt;
	Edges() {
		nbr = 0;
		wt = 0;
	}
	Edges(int d, int w): nbr(d), wt(w) {}
};


void dfs(unordered_map<int, vector<Edges>>& graph, unordered_map<int, bool>& visited, int src) {
	visited[src] = true;
	for(auto nb: graph[src]) {
		if(!visited[nb.nbr]) dfs(graph, visited, nb.nbr);
	}
	return;
}

bool isPath(unordered_map<int, vector<Edges>>& graph, int src, int dest) {
	unordered_map<int, bool> visited;
	dfs(graph, visited, src);
	return visited[dest];
}

int main() {
	int v, e;
	cin>>v>>e;
	unordered_map<int, vector<Edges>> graph;
	for(int i=0;i<v;i++) {
		int s, nb, wt;
		cin>>s>>nb>>wt;
		graph[s].push_back(Edges(nb, wt));
		graph[nb].push_back(Edges(s, wt));

	}
	int src, dest;
	cin>>src>>dest;
	bool x = isPath(graph, src, dest);
	cout<<x<<endl;
	return 0;
}