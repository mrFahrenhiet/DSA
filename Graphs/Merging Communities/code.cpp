#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int find(int x, vector<int> &parents) {
	if(parents[x]==-1) {
		return x;
	}
	return parents[x] = find(parents[x], parents);
}

void unionSet(int x, int y, vector<int> &parents, vector<int> &rank) {
	int s1 = find(x, parents);
	int s2 = find(y, parents);

	if(s1!=s2) {
		if(rank[s1]<rank[s2]) {
				parents[s1] = s2;
				rank[s2]+=rank[s1];
			}
			else {
				parents[s2] = s1;
				rank[s1]+=rank[s2];
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,q;
    cin>>n>>q;
    vector<int> parents(n+1,-1);
    vector<int> rank(n+1,1);
    vector<string> tokens;
    string s;
    getline(cin, s);
    while(q--) {
    	string s;
    	getline(cin, s);
    	stringstream check1(s);
    	string intermidiate;
    	while(getline(check1, intermidiate, ' ')) {
    		tokens.push_back(intermidiate);
    	}
    	if(tokens[0]=="Q") {
    		int parent = find(stoi(tokens[1]), parents);
    		if(parent==-1) {
    			cout<<rank[stoi(tokens[1])]<<endl;
    		}
    		else {
    			cout<<rank[parent]<<endl;
    		}
    	}
    	else if(tokens[0]=="M") {
    		unionSet(stoi(tokens[1]), stoi(tokens[2]), parents, rank);
    	}
    	tokens.clear();
    }
    return 0;

}