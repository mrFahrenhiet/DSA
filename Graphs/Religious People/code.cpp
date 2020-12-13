#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Graph {
	map<ll,list<ll>> m;
public:
	void addEdge(ll src,ll dest) {
		m[src].push_back(dest);
		m[dest].push_back(src);
	}
	void dfsUtil(ll t,vector<bool> &visited,ll &nos) {
		visited[t] = true;
		nos++;
		for(auto nbr: m[t]) {
			if(!visited[nbr]) {
				dfsUtil(nbr,visited,nos);
			}
		}
	}
	ll dfs(ll a,ll b,ll temple) {
		ll count=0;
		ll cost = 0;
		vector<bool> visited(temple+1,false);
		for(ll k=1;k<visited.size();k++) {
			ll nos = 0;
			if(!visited[k]) {
				dfsUtil(k,visited,nos);
				count++;
				cost += (nos-1)*b;
			}
		}
		cost += count*a;
		return cost;
	}
};
int main(){
	#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
	#endif
	ll t;
	cin>>t;
	while(t--) {
		ll temple,roads,a,b;
		cin>>temple>>roads>>a>>b;
		Graph g;
		for(ll i=0;i<roads;i++) {
			ll u,v;
			cin>>u>>v;
			g.addEdge(u,v);
		}
		if(a>b) {
			cout<<g.dfs(a,b,temple)<<endl;
		}
		else {
			cout<<a*temple<<endl;
		}
	}
	return 0;
}