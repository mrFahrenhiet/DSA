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

class Container {
public:
	int node;
	string path;
	int weight;
	Container(int n, string p, int w): node(n), path(p), weight(w) {}
};

class Comp {
public:
	bool operator()(Container a, Container b) {
		return a.weight > b.weight;
	}
};

vector<Container> dijkstras(vector<vector<Edge>>& graph, int src) {
	vector<bool> visited(graph.size(), false);
	vector<Container> res;
	priority_queue<Container, vector<Container>, Comp> pq;
	pq.push(Container(src, to_string(src), 0));
	while(!pq.empty()) {
		auto temp = pq.top();
		pq.pop();
		if(visited[temp.node]) continue;
		else visited[temp.node] = true;
		res.push_back(temp);
		for(auto nbr: graph[temp.node]) {
			if(!visited[nbr.d]) pq.push(Container(nbr.d, temp.path + to_string(nbr.d), nbr.w + temp.weight));
		}
	}
	return res;
}

int main() {
	int v,e;
	cin>>e>>v;
	vector<vector<Edge>> graph;
	for(int i=0;i<e;i++) graph.push_back({});
	for(int i=0;i<v;i++) {
		int source, destination, weight;
		cin>>source>>destination>>weight;
		graph[source].push_back(Edge(destination, weight));
		graph[destination].push_back(Edge(source, weight));
	}
	vector<Container> ans = dijkstras(graph, 0);
	for(auto a: ans) cout<<0<<" "<<a.node<<" "<<a.path<<" "<<a.weight<<endl;
	return 0;
}