#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Triple {
public:
	string place;
	int train;
	int flight;
};
class Graph {
	map<string,list<Triple>> m;
public:
	void addEdge(string src, string dest, int t, int f) {
		Triple inp;
		inp.place = dest;
		inp.train = t;
		inp.flight = f;
		m[src].push_back(inp);
		inp.place = src;
		m[dest].push_back(inp);
	}
	void printGraph() {
		for(auto itr: m) {
			string src = itr.first;
			list<Triple> lp = itr.second;
			cout<<src<<"->";
			for(auto nbrs: lp) {
				cout<<nbrs.place<<" "<<nbrs.train<<" "<<nbrs.flight<<",";
			}
			cout<<endl;
		}
	}
	map<string,int> dijkstras(string src) {
		map<string,int> dist;
		set<pair<int,string>> s;
		for(auto itr:m) {
			dist[itr.first] = INT_MAX;
		}
		dist[src] = 0;
		s.insert(make_pair(0,src));
		while(!s.empty()) {
			auto temp = *s.begin();
			string node = temp.second;
			int nodeDist = temp.first;
			s.erase(temp);
			for(auto nbr: m[node]) {
				if(dist[nbr.place]>nodeDist+nbr.train) {
					auto f = s.find(make_pair(dist[nbr.place],nbr.place));
					if(f!=s.end()) {
						s.erase(f);
					}
					dist[nbr.place] = nodeDist+nbr.train;
					s.insert(make_pair(dist[nbr.place],nbr.place));
				}
			}
		}
		return dist;
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
    g.addEdge("DELHI","BHOPAL",7,11);
    g.addEdge("DELHI","JAIPUR",2,6);
    g.addEdge("JAIPUR","PUNE",6,5);
    g.addEdge("AMRITSAR","DELHI",3,8);
    g.addEdge("AMRITSAR","JAIPUR",5,4);
    g.addEdge("BHOPAL","MUMBAI",6,3);
    g.addEdge("MUMBAI","PUNE",2,1);
    g.addEdge("PUNE","GOA",11,6);
    g.addEdge("GOA","AMRITAPURI",13,12);
    g.addEdge("MUMBAI","AMRITAPURI",8,7);
    g.addEdge("BHOPAL","AMRITAPURI",1,2);
    g.printGraph();
    map<string,int> dist1 = g.dijkstras("DELHI");
    map<string,int> dist2 = g.dijkstras("AMRITAPURI");
    for(auto i: dist1) {
    	cout<<i.first<<"="<<i.second<<endl;
    }
    cout<<endl;
    for(auto i: dist2) {
    	cout<<i.first<<"="<<i.second<<endl;
    }
	return 0;
}