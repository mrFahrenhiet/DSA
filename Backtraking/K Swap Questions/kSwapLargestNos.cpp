#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Solution {
private:
    void findMaxUtil(string str, string& res, int k, int i) {
        if(i>=str.length() or k<=0) return;
        // find nos to replace first nos;
        char mxm = str[i];
        for(int l=i+1;l<str.length();l++) {
            if(mxm<str[l]) mxm = str[l];
        }
        if(mxm==str[i]) this->findMaxUtil(str, res, k, i+1);
        else {
            for(int j=i;j<str.length();j++) {
                if(str[j]==mxm) {
                    swap(str[i], str[j]);
                    if(str.compare(res)>0) res = str;
                    this->findMaxUtil(str, res,k-1, i+1);
                    swap(str[i], str[j]);
                }
            }
        }
        return;
    }
public:
    string findMaxNos(string str, int k) {
        string res = str;
        this->findMaxUtil(str, res, k, 0);
        return res;
    }
};


int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int k;
    string str;
    cin>>k>>str;
    Solution s;
    cout<<s.findMaxNos(str, k);
    return 0;

}