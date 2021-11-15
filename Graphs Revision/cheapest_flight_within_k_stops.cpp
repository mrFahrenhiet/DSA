#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class Collection {
public:
    int node;
    int weight;
    int stops;
    Collection(int n, int w, int s): node(n), weight(w), stops(s) {}
};

class Compare {
public:
    bool operator()(Collection a, Collection b) {
        return a.weight > b.weight;
    }
};


// in the visited array see the path to node i with minimum stops
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<int>> graph(n, vector<int>(n, -1));
    priority_queue<Collection, vector<Collection>, Compare> pq;
    vector<int> path(n, INT_MAX);
    for(int i=0;i<flights.size();i++) graph[flights[i][0]][flights[i][1]] = flights[i][2];
    pq.push(Collection(src, 0, 0));
    while(!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        if(temp.node==dst) return temp.weight;
        if(temp.stops >= k+1) continue;
        if(path[temp.node] > temp.stops) {
            path[temp.node] = temp.stops;
            for(int j=0;j<graph[temp.node].size();j++) {
                if(graph[temp.node][j]!=-1)
                    pq.push(Collection(j, temp.weight + graph[temp.node][j], temp.stops+1));
            }
        }
    }
    return -1;
}

int main() {
	int e,v;
	cin>>e>>v;
	vector<vector<int>> flights;
	for(int i=0;i<v;i++) {
		int s, d, w;
		cin>>s>>d>>w;
		flights.push_back({s,d,w});
	}
	int src, dst, k;
	cin>>src>>dst>>k;
	int ans = findCheapestPrice(e, flights, src, dst, k);
	cout<<ans<<endl;
	return 0;
}