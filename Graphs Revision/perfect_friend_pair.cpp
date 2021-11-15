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


void dfs(unordered_map<int, vector<Edges>>& graph, unordered_map<int, bool>& visited, vector<int>& node , int src) {
	visited[src] = true;
	node.push_back(src);
	for(auto nb: graph[src]) {
		if(!visited[nb.nbr]) dfs(graph, visited, node, nb.nbr);
	}
	return;
}

vector<vector<int>> friends_per_soc(unordered_map<int, vector<Edges>>& graph, int e) {
	int res = 0;
	unordered_map<int, bool> visited;
	vector<vector<int>> nodes;
	vector<int> node;
	for(int i=0;i<e;i++) {
		if(!visited[i]) {
			res++;
			dfs(graph, visited, node, i);
			nodes.push_back(node);
			node.clear();
		}
	}
	return nodes;
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
	vector<vector<int>> nodes = friends_per_soc(graph, e);
	for(auto nodelst: nodes) {
		cout<<"Soc"<<endl;
		for(auto nd: nodelst) cout<<nd<<" ";
		cout<<endl;
	}
	return 0;
}