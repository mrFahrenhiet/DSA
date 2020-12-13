#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <array>
#include <list>
#include <climits>

using namespace std;

template<typename T>
class Graph {
    map<T,list<pair<T,int> > > m;
    stack
public:
    void addEdge(T x,T y,bool bi,int dist) {
        m[x].push_back(make_pair(y,dist));
        if(bi)
            m[y].push_back(make_pair(x,dist));
    }

    void printGraph() {
        for(auto itr: m) {
            cout<<itr.first<<"->";
            for(auto it: itr.second) {
                cout<<"("<<it.first<<"-"<<it.second<<")"<<", ";
            }
            cout<<endl;
        }
        return;
    }

    void dikstras(T src) {
        map<T,int> dist;
        for(auto itr: m) {
            dist[itr.first] = INT_MAX;
        }
        dist[src] = 0;
        set<pair<int,T>> s;
        s.insert(make_pair(0,src));
        while(!s.empty()) {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            dist[src] = 0;
            s.erase(s.begin());
            for(auto nbr: m[node]) {
                if(dist[nbr.first]>nodeDist+nbr.second) {
                    auto f = s.find(make_pair(dist[nbr.first],nbr.first));
                    if(f!=s.end()) {
                        s.erase(f);
                    }
                    dist[nbr.first] = nodeDist + nbr.second;
                    s.insert(make_pair(dist[nbr.first],nbr.first));
                }
            }
        }
        cout<<"Distance From: "<<src<<endl;
        for(auto d:dist) {
        	cout<<d.first<<"->";
			if(d.second==INT_MAX) {
				cout<<-1<<" ";
			}

			else if(d.first!=src)
				cout<<d.second<<" ";
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
    int t;
    cin>>t;
    while(t--) {
    	Graph<int> g;
    	int m,n;
    	cin>>n>>m;
    	for(int i=0;i<n;i++) {
    		int a,b,w;
    		cin>>a>>b>>w;
    		g.addEdge(a,b,true,w);
    	}
    	int s;
    	cin>>s;
    	g.printGraph();
    	cout<<endl;
    	g.dikstras(s);
	}
    return 0;

}