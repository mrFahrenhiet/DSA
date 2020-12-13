#include <bits/stdc++.h>
using namespace std;
vector<string> vs;
void permute(string &s,string &o,int i) {
    if(s[i]=='\0') {
        if(o<s) {
            vs.push_back(s);
        }
        return;
    }
    for(int j=i;s[j]!='\0';j++) {
        swap(s[i],s[j]);
        permute(s,o,i+1);
        swap(s[j],s[i]);
    }
}
int main() {
    string s,o;
    cin>>s;
    o=s;
    permute(s,o,0);
	sort(vs.begin(),vs.end());
	for(int i=0;i<vs.size();i++) {
		cout<<vs[i]<<endl;
	}
}