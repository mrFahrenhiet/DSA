#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<string> split(const string& str, const string& delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

void getOpTime(vector<vector<string> > &inp) {
	vector<int> res(inp.size()/2);
	stack<int> s;
	for(int i=0;i<inp.size();i++) {
		if(s.empty()) s.push(stoi(inp[i][0]));
		else if(inp[i][1]=="start") {
			res[s.top()] += stoi(inp[i][2]) - stoi(inp[i-1][2]);
			s.push(stoi(inp[i][0])); 
		}
		if(!s.empty() and inp[i][1]=="end") {
			if(inp[i-1][1]=="end") res[s.top()] += stoi(inp[i][2]) - stoi(inp[i-1][2]);
			else res[s.top()] += stoi(inp[i][2]) + 1 - stoi(inp[i-1][2]);
			s.pop();
		}
	}
	for(auto r: res) cout<<r<<" ";
	cout<<endl;
	return;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n, tn;
    cin>>n>>tn;
    vector<vector<string>> inp;
    vector<string> tmp;
    while(tn--) {
    	string temp;
    	cin>>temp;
    	tmp = split(temp, ":");
    	inp.push_back(tmp);
    	tmp.clear();
    }
    getOpTime(inp);
    return 0;

}