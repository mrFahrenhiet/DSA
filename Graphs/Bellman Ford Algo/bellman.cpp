#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge {
public:
	int src,dest,weight;
};
class Graph {
public:
	int v, e;
	Edge *edge;
	Graph(int v,int e) {
		this->v = v;
		this->e = e;
	}
	void addEdge(int u,int v,int w,int count) {
		edge[count].src = u;
		edge[count].dest = v;
		edge[count].weight = w;
	}
	void BellmanFord(int src) {
		int dist[v];
		for(int i=0;i<v;i++) {
			if(i==src) {
				dist[i]=0;
			}
			else {
				dist[i] = INT_MAX;
			}
		}
		//Relaxation
		for(int i=1;i<=v-1;i++) {
			for(int j=0;j<e;j++) {
				int src = edge[j].src;
				int dest = edge[j].dest;
				int w = edge[j].weight;
				//Relax check
				if(dist[src]!=INT_MAX and dist[src]+w<dist[dest]) {
					dist[dest] = dist[src] + w;
				}
			}
		}
		for(int j=0;j<e;j++) {
				int src = edge[j].src;
				int dest = edge[j].dest;
				int w = edge[j].weight;
				//Relax check
				if(dist[src]!=INT_MAX and dist[src]+w<dist[dest]) {
					cout<<"Graph has a -ve cycle"<<endl;
					return;
				}
			}
			for(int i=0;i<v;i++) {
				cout<<i<<"-"<<dist[i]<<endl;
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
    
    return 0;

}