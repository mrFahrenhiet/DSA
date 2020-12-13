#include <iostream>
using namespace std;
int cvt_to_bin(int n) {
    int ans=0,p=1;
    while(n>0) {
        int l = n&1;
        ans+=p*l;
        p*=10;
        n=n>>1;
    }
    return ans;
}
int main() {
    cout<<cvt_to_bin(100);
}
