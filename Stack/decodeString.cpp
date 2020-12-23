#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string decode(string s, int &pos) {
    int num = 0;
    string word = "";
    for(;pos<s.size();pos++) {
        if(s[pos]=='[') {
            string t = decode(s, ++pos);
            for(;num>0;num--) word += t;
        }
        else if(isdigit(s[pos])) {
            num  = num*10 + (s[pos]-'0');
        }
        else if(s[pos]==']') return word;
        else word += s[pos];
    }
    return word;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin>>s;
    int pos = 0;
    string res = decode(s, pos);
    cout<<res<<endl;
    return 0;

}