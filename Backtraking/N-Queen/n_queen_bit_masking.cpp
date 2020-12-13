#include<iostream>
#include<vector>
#include<bitset>
#define ll long long int
using namespace std;
int count=0,DONE;
void n_queen(int r_m,int ld,int rd) {
    if(r_m==DONE) {
        count++;
        return;
    }
    int safe = DONE & (~(r_m|ld|rd));
    while(safe) {
        int p = safe & (-safe);
        safe = safe - p;
        n_queen(r_m|p,(ld|p)<<1,(rd|p)>>1);
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    DONE = ((1<<n) -1);
    n_queen(0,0,0);
    cout<<count;
    return 0;

}