#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Graph {
	unordered_map<string, list<pair<string,int> > > l;
public:
	void addEdge(string x, string y,bool bidir, int wt) {
		l[x].push_back(make_pair(y,wt));
		if(bidir) {
			l[y].push_back(make_pair(x,wt));
		}
	}

	void printGraph() {
		for(auto p: l) {
			string c = p.first;
			list<pair<string,int>> lp = p.second;
			cout<<c<<"->";
			for(auto nbrs: lp) {
				cout<<nbrs.first<<" "<<nbrs.second<<",";
			}
			cout<<endl;
		}
	}

	void bsf(string s) {
		map<string,bool> visited;
		queue<string> q;
		q.push(s);
		visited[s] = true;
		while(!q.empty()) {
			string temp = q.front();
			q.pop();
			for(auto itr: l[temp]) {
				if(!visited[itr.first])
					q.push(itr.first);
			}
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
    Graph g;
    g.addEdge("A","B",true,50);
    g.addEdge("A","C",true,10);
    g.addEdge("B","D",true,40);
    g.addEdge("C","D",true,30);
    g.addEdge("A","D",false,50);
    g.printGraph();
    return 0;

}