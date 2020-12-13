#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Gdata {
public:
	int src;
	int dest;
	int wt;
};

bool comp(Gdata g1,Gdata g2) {
	if(g1.wt==g2.wt) {
		return g1.src<g2.src;
	}
	return g1.wt<g2.wt;
}

class Graph {
	int V;
	vector<Gdata> l;
public:
	Graph(int v) {
		this->V = v;
	}
	void addEdge(int x,int y,int w) {
		Gdata g;
		g.src = x;
		g.dest = y;
		g.wt = w;
		l.push_back(g);
	}
	void printGraph() {
		for(auto itr: l) {
			cout<<itr.src<<"-"<<itr.dest<<"->"<<itr.wt<<endl;
		}
	}
	int findSet(int x,vector<int> &parent) {
		if(parent[x]==-1)
			return x;
		return parent[x] = findSet(parent[x],parent);
	}
	void unionSet(int x,int y,vector<int> &parent,vector<int> &rank) {
		int s1 = findSet(x,parent);
		int s2 = findSet(y,parent);
		if(s1!=s2) {
			if(rank[s1]>=rank[s2]) {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
			else {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
		}
	}
	int mst() {
		vector<int> parent(V+1,-1);
		vector<int> rank(V+1,1);
		sort(l.begin(), l.end(),comp);
		int ans = 0;
		for(auto i:l) {
			int sr = i.src;
			int dst = i.dest;
			int w = i.wt;
			int s1 = findSet(sr,parent);
			int s2 = findSet(dst,parent);
			if(s1!=s2) {
				unionSet(s1,s2,parent,rank);
				//cout<<sr<<"-"<<dst<<"="<<w<<endl;
				ans+=w;
			}
		}
		return ans;
	}

};
int main() {
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	Graph g(n);
	for(int i=0;i<m;i++) {
		int x,y,w;
		cin>>x>>y>>w;
		g.addEdge(x,y,w);
	}
	cout<<g.mst();
	//g.printGraph();
	return 0;
}