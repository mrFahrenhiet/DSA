#include<bits/stdc++.h>
#define ll long long int
using namespace std;
string minWindow(string str, string pat) {
    int fs[26] = {0};
    int fp[26] = {0};
    int cnt = 0,start=0, startFinal=0;
    int minWindowLen=INT_MAX;
    for(auto p: pat) {
        fp[p-'A']++;
    }
    for(int end=0;end<str.size();end++) {
        fs[str[end]-'A']++;
        if(fp[str[end]-'A']>0 and fs[str[end]-'A']<=fp[str[end]-'A']) cnt++;
        //cout<<cnt<<endl;
        if(cnt==pat.length()) {
        	cout<<fp[str[start]-'A']<<" "<<fs[str[start]-'A']<<endl;
            while(fp[str[start]-'A']==0 or fp[str[start]-'A']<fs[str[start]-'A']) {
                if(fs[str[start]-'A']> fp[str[start]-'A'])
                    fs[str[start]-'A']--;
                start++;
            }
            int windowLen = (end-start+1);
            if(windowLen<minWindowLen) {
                minWindowLen = windowLen;
                startFinal = start;
            }
        }
    }
    string res = str.substr(startFinal, minWindowLen);
    return res;
}
int main() {
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    string str,pat;
    cin>>str>>pat;
    string x = minWindow(str, pat);
    cout<<x<<endl;
    return 0;

}