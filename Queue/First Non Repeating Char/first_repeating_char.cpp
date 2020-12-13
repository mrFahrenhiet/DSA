#include <bits/stdc++.h>
using namespace std;
void fst_non_r(char a[]) {
    queue<char> q;
    vector<int> v(126,0);
    for(int i=0;a[i]!='\0';i++) {
        q.push(a[i]);
        v[a[i]]++;
        while(!q.empty()) {
            char y = q.front();
            if(v[y]>1) {
                q.pop();
            }
            else {
                cout<<y<<" ";
                break;
            }
        }
        if(q.empty()) {
            cout<<-1<<" ";
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
    char a[190];
    cin>>a;
    fst_non_r(a);
}
