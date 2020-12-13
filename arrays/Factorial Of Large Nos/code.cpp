#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int multiply(ll n, vector<ll> &resArr, int resArrSize) {
    int carry = 0, mulRes;
    for(int i=0;i<resArrSize;i++) {
        mulRes = n*resArr[i] + carry;
        carry = mulRes/10;
        resArr[i] = mulRes%10;
    }
    while(carry) {
        resArr[resArrSize++] = carry%10;
        carry /= 10;
    }
    return resArrSize;
}
void extraLargeFact(ll n) {
    ll resArrSize = 1;
    vector<ll> resArr(2000,0);
    resArr[0] = 1;
    for(int i=1;i<=n;i++) {
        resArrSize = multiply(i,resArr, resArrSize);
    }
    for(int i=resArrSize-1;i>=0;i--) {
        cout<<resArr[i];
    }
    cout<<endl;
    cout<<resArrSize;
    return;
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
    extraLargeFact(n);
}
