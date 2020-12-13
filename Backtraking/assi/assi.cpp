#include <bits/stdc++.h>
using namespace std;
vector<string> vs;
// int count = 0;
bool shouldSwap(string str,int start,int curr) { 
    for(int i=start;i<curr;i++)  
        if (str[i]==str[curr]) 
            return 0; 
    return 1; 
}
bool shouldAdd(string &s) {
    for(int word=0;s[word]!='\0';word++) {
        if(s[word]=='b'&&s[word+1]=='b') {
            return false;
        }
    }
    return true;
}
void permute(string &s,int i) {
    if(s[i]=='\0') {
        if(shouldAdd(s)) {
            vs.push_back(s);
        }
        return;
    }
    for(int j=i;s[j]!='\0';j++) {
        if(shouldSwap(s,i,j)) {
            swap(s[i],s[j]);
            permute(s,i+1);
            swap(s[j],s[i]);
        }
    }
}


void make_nos(string &v,unsigned int i,int n) {
    if(i>=v.size()) {
        return;
    }
    permute(v,0);
    sort(vs.begin(),vs.end());
    v[i] = 'b';
    make_nos(v,i+1,n);
}
int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,t;
    cin>>t;
    for(int ca=0;ca<t;ca++) {
        cin>>n;
        string v(n,'a');
        make_nos(v,0,n);
        if(n==1) {
            cout<<"#"<<n<<" : "<<2<<endl;
        }
        else {
            cout<<"#"<<n<<" : "<<vs.size()<<endl;
        }
        vs.clear();
    }
}
