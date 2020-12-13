#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Graph {
	map<string,list<string>> m;
public:
	void addEdge(string src,string dest) {
		m[src].push_back(dest);
	}

	void topo() {
		map<string,int> indegree;
		for(auto itr:m) {
			for(auto it: itr.second) {
				indegree[it]++;
			}
		}
		queue<string> q;
		for(auto itr:m) {
			if(indegree[itr.first]==0) {
				q.push(itr.first);
			}
		}
		while(!q.empty()) {
			string temp = q.front();
			cout<<temp<<endl;
			q.pop();
			for(auto nbr: m[temp]) {
				indegree[nbr]--;
				if(indegree[nbr]==0) {
					q.push(nbr);
				}
			}
		}
		for(auto it: indegree) {
			if(it.second>0)
				cout<<it.first<<endl;
		}
		return;
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
    g.addEdge("C++","Data Preprocessing");
    g.addEdge("Python","Data Preprocessing");
    g.addEdge("C++","ML Basics");
    g.addEdge("Data Preprocessing","ML Basics");
    g.addEdge("Python","ML Basics");
    g.addEdge("C++","DL");
    g.addEdge("Python","Pytorch");
    g.addEdge("Pytorch","DL");
    g.addEdge("DL","Pytorch");
    g.addEdge("ML Basics","DL");
    g.addEdge("ML Basics","Pytorch");
    g.topo();
	return 0;
}