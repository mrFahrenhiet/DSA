#include <bits/stdc++.h>
using namespace std;
void permute(string &s,string &o,int i) {
    if(s[i]=='\0') {
        if(o<s) {
            cout<<s<<endl;
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
}
