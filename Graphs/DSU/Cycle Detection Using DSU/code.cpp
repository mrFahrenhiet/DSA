#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Graph {
	int V;
	list<pair<int,int> > l;

public:

	Graph(int v) {
		this->V = v;
	}

	void add_edge(int x, int y) {
		l.push_back(make_pair(x,y));
	}

	// Slower O(n) approach
	// int find(int i,vector<int> &parent) {
	// 	while(parent[i]!=-1) {
	// 		i = parent[i];
	// 	}
	// 	return i;
	// }

	// O(n) for single run and then it is O(1) top down optimization
	int find(int i,vector<int> &parent) {
		if(parent[i]==-1) {
			return i;
		}
		return parent[i] = find(parent[i],parent);
	}

	// Slower O(logn) approach
	// void union_set(int x, int y, vector<int> &parent) {
	// 	int s1 = find(x,parent);
	// 	int s2 = find(y,parent);

	// 	if(s1!=s2) {
	// 		parent[s2] = s1;
	// 	}
	// }


	// O(1)
	void union_set(int x, int y, vector<int> &parent, vector<int> &rank) {
		int s1 = find(x,parent);
		int s2 = find(y,parent);

		if(s1!=s2) {
			if(rank[s1]<rank[s2]) {
				parent[s1] = s2;
				rank[s2]+=rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1]+=rank[s2];
			}
		}
	}

	bool cycle_detect() {
		vector<int> parent(V+1,-1);
		vector<int> rank(V+1,1);

		for(auto itr: l) {
			int edge1 = itr.first;
			int edge2 = itr.second;

			int s1 = find(edge1,parent);
			int s2 = find(edge2,parent);

			if(s1==s2) {
				cout<<"Same parent "<<s1<<" and "<<s2<<endl;
				return true;
			}
			else {
				union_set(s1,s2,parent,rank);
			}
		}

		return false;
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
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(4,1);

    bool x = g.cycle_detect();
    cout<<x<<endl;

    return 0;

}