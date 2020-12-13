#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void find_subs(string s, int k) {
    vector<int> m(258,0);
    int fs,fe;
    int maxLen = 0;
    int tk = k;
    int start=0,end=start;
    while(end<s.size()) {
        if(m[s[end]]==0) {
            if(k==0) {
                if(maxLen<end-start) {
                    fs = start;
                    fe = end;
                    maxLen = end-start;
                }
                int x = m[s[start]];
                start = x;
                end = start;
                fill(m.begin(),m.end(),0);
                k = tk;
            }
            k--;
        }
        m[s[end]] = end+1;
        end++;
    }
    // if(k!=0) {
    // 	cout<<"Max string not found!"<<endl;
    // 	return;
    // }
    if(maxLen<end-start) {
        fs = start;
        fe = end;
        maxLen = end-start;
    }
    cout<<s.substr(fs,maxLen)<<" "<<maxLen;
    return;
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
    int k;
    cin>>k;
    find_subs(s,k);
	return 0;
}