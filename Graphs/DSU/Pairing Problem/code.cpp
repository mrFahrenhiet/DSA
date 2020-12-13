#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Graph {
	int V;
	list<pair<int,int>> l;
public:
	Graph(int v) {
		this->V = v;
	}
	void addEdge(int x,int y) {
		l.push_back(make_pair(x,y));
	}
	int findSet(int x,vector<int> &parent) {
		if(parent[x]==-1)
			return x;

		return parent[x] = findSet(parent[x],parent);
	}

	void unionSet(int x,int y,vector<int> &parent, vector<int> &rank) {
		int s1 = findSet(x,parent);
		int s2 = findSet(y,parent);
		if(s1!=s2) {
			if(rank[s1]>=rank[s2]) {
				parent[s2] = s1;
				rank[s1]+=rank[s2];
			}
			else {
				parent[s1] = s2;
				rank[s2]+=rank[s1];
			}
		}
		return;
	}
	int pairing() {
		vector<int> parent(V+1,-1);
		vector<int> rank(V+1,1);
		for(auto itr: l) {
			int x = itr.first;
			int y = itr.second;
			unionSet(x,y,parent,rank);
		}
		int ans = 0;
		for(int i=0;i<V;i++)
			ans+= V - rank[findSet(i,parent)];
		
		return ans/2;
	}
};
int main() {
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,3);
    g.addEdge(0,4);
    int x = g.pairing();
    cout<<x<<endl;
	return 0;
}