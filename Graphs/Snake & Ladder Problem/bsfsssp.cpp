#include<bits/stdc++.h>
#define ll long long int
using namespace std;
template<typename T>
class Graph {
	unordered_map<T, list<T>> l;

public:
	void addEdge(T x, T y) {
		l[x].push_back(y);
		// l[y].push_back(x);
	}

	void bfs(T src,T dest) {
		map<T,int> dist;
		// map<T,T> parent;
		queue<T> q;

		for(auto n_p:l) {
			T n = n_p.first;
			dist[n] = INT_MAX;
			// parent[n] = n;
		}
		q.push(src);
		dist[src] = 0;

		while(!q.empty()) {
			T node = q.front();
			q.pop();

			for(auto nbr:l[node]) {
				if(dist[nbr]==INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[node]+1;
					// parent[nbr] = node;
				}
			}
		}

		cout<<dist[dest]<<endl;
		// T temp = dest;
		// while(temp!=src) {
		// 	cout<<temp<<"->";
		// 	temp = parent[temp];
		// }
		// cout<<temp<<endl;
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
    int t;
    cin>>t;
    while(t--) {
    	int n,l,s;
	    cin>>n>>l>>s;
	    int board[64] = {0};
	    for(int lad=0;lad<l;lad++) {
	    	int no,amt;
	    	cin>>no>>amt;
	    	board[no] = amt-no;
	    }
	    for(int sn=0;sn<s;sn++) {
	    	int no,amt;
	    	cin>>no>>amt;
	    	board[no] = (amt-no)*(-1);
	    }
	    Graph<int> g;
	   for(int i=1;i<=n;i++) {
	   	for(int d=1;d<=6;d++) {
	   		int j = i+d;
	   		j += board[j];
	   		if(j<=n+10) {
	   			g.addEdge(i,j);
	   		}
	   	}
	   }
	   // g.addEdge(36,36);
	   g.bfs(1,n);
    }
   return 0;

}