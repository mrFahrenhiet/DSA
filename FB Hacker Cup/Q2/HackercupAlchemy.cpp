#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t ;cin>>t ; 
    for(int k =1 ; k <=t ; k++)
    {
        int n ; cin>>n ; 
        string s ; 
        cin>>s ; 
        unordered_map<char,int> um ; 
        um['A'] = 0 ;
        um['B'] = 0 ; 
        for(int i = 0 ; i < s.length(); i++)
        {
            um[s[i]]++ ;
        }
        //cout<<um['A']<<" "<<um['B']<<" "; 
        if(um['A'] - um['B'] == 1 || um['A'] - um['B'] == -1 )
        {
            cout<<"Case #"<<k<<": Y\n"; 
        }
        else
        {
            cout<<"Case #"<<k<<": N\n"; 
        }
    }
}
