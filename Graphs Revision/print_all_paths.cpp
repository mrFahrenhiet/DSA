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

vector<pair<vector<int>, int>> all_paths;

void dfs(unordered_map<int, vector<Edges>>& graph, unordered_map<int, bool>& visited, vector<int>& path, int src, int dest, int len=0) {
	visited[src] = true;
	path.push_back(src);
	if(src==dest) {
		all_paths.push_back({path, len});
		return;
	}
	for(auto nb: graph[src]) {
		if(!visited[nb.nbr]) {
			len += nb.wt;
			dfs(graph, visited, path, nb.nbr, dest, len);
			visited[nb.nbr] = false;
			len -= nb.wt;
			path.pop_back();
		}
	}
	return;
}

bool allPaths(unordered_map<int, vector<Edges>>& graph, int src, int dest) {
	unordered_map<int, bool> visited;
	vector<int> path;
	path.clear();
	dfs(graph, visited, path, src, dest, 0);
	for(auto itm: all_paths) {
		for(auto el: itm.first) cout<<el<<" ";
		cout<<"@ "<<itm.second<<" ";
		cout<<endl;
	}
	return visited[dest];
}

int main() {
	int v, e;
	cin>>e>>v;
	unordered_map<int, vector<Edges>> graph;
	for(int i=0;i<v;i++) {
		int s, nb, wt;
		cin>>s>>nb>>wt;
		graph[s].push_back(Edges(nb, wt));
		graph[nb].push_back(Edges(s, wt));

	}
	bool x = allPaths(graph, 0, e-1);
	return 0;
}