class Graph {
	int V;
	list<int> *l;

public:
	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
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
	bool cycHelp(int src,bool visited[],bool stack[]) {
		visited[src] = true;
		stack[src] = true;
		for(auto it: l[src]) {
			if(stack[it]==true) {
				return true;
			}
			else if(visited[it]==false) {
				bool cycF = cycHelp(it,visited,stack);
				if(cycF==true) {
					return true;
				}
			}
		}
		//pop
		stack[src] = false;
		return false;
	}
	void cyc(int src) {
		// bool *visited = new bool[V];
		// bool *stack  = new bool[V];
		bool visited[50];
		bool stack[50];
		for(int i=0;i<V;i++) {
			visited[i] = stack[i] = false;
		}
		cout<<cycHelp(src,visited,stack);
	}
};

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,5);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(4,2);
    g.addEdge(5,6);
    g.cyc(0);
    return 0;

}