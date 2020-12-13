#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Graph {
	int V;
	list<int> *l;

public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool bi=true) {
		l[x].push_back(y);
		if(bi==true)
			l[y].push_back(x);
	}

	void printGraph() {
		for(int i=0;i<V;i++) {
			cout<<"Vectex:"<<i<<"->";
			for(auto x:l[i]) {
				cout<<x<<",";
			}
			cout<<endl;
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
    Graph g(4);
    g.addEdge(0,1,false);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.printGraph();
    return 0;

}