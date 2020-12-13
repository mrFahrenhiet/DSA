#include <iostream>
#include <string>
using namespace std;
void gen_bracks(int N,int i,char *ch,int open,int close) {
    if(i>=2*N) {
        ch[i] = '\0';
        cout<<ch;
        cout<<endl;
        return;
    }
    if(open<N) {
        ch[i] = '(';
        gen_bracks(N,i+1,ch,open+1,close);
    }
    if(close<open) {
        ch[i] = ')';
        gen_bracks(N,i+1,ch,open,close+1);
    }
}
int main() {
    int n;
    cin>>n;
    char ch[100];
    gen_bracks(n,0,ch,0,0);
}
