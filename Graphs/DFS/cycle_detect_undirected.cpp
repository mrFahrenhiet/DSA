#include<bits/stdc++.h>
#define ll long long int
using namespace std;

template<typename T>
class Graph {
private:
	unordered_map<T, vector<T>> l;
public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	bool cycHelp(T src, unordered_map<T,bool>& visited, T parent) {
		visited[src] = true;
		for(auto nbr: l[src]) {
			if(visited[nbr]==true && parent!=nbr) return true;
			else if(!visited[nbr]) {
				if(cycHelp(nbr, visited, src)) return true;
			}
		}
		return false;
	}

	bool findcyc(T src) {
		unordered_map<T,bool> visited;
		bool x = cycHelp(src,visited, src);
		return x;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    cout<<g.findcyc(0)<<endl;
    return 0;
}