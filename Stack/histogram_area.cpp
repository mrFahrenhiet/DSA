#include<iostream>
#include<stack>
#include<vector>
#include<climits>
#define ll long long int
using namespace std;

int histogram_area(vector<int> &v) {
    stack<int> s;
    int area = INT_MIN;
    s.push(0);
    for(int i=1;i<v.size();i++) {
        if(v[i]>v[s.top()]) {
        	s.push(i);
        }
        else {
        	int x;
        	while(v[i]<v[s.top()] && !s.empty()) {
        		x = s.top();
        		s.pop();
        		int a = v[x]*(s.empty()?i:(i-s.top()-1));
        		area = max(a,area);
        		if(s.empty())
        			break;
        	}
        	s.push(i);
        }
    }
    int i = v.size();
    while(!s.empty()) {
    	int x = s.top();
    	s.pop();
    	area = max(area,v[x]*(s.empty()?i:(i-s.top()-1)));
    }
    return area;
}

int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int no;
        cin>>no;
        v.push_back(no);
    }
    cout<<histogram_area(v)<<endl;
    return 0;

}