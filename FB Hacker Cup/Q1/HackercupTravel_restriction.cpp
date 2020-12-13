#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int i , int j,vector<vector<bool>> vec,vector<bool> ip,vector<bool> op)
{
    if(i > j)
    {
        return (vec[i-1][j] && op[i] && ip[i-1]) ; 
    }
    if(i < j )
    {
        return (vec[i][j-1] && op[j-1] && ip[j]) ; 
    }
    return true ; 
}
int main() 
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int t ; cin>>t ; 
    for(int k = 1; k <= t ; k++)
    {
        cout<<"Case #"<<k<<":\n"  ;
        vector<bool> ip; 
        vector<bool> op ; 
        int n ; cin >> n ; 
        for(int i = 0 ; i < n ; i++)
        {
            
            char c ; cin>>c ; 
            if(c=='Y')
            {
                ip.push_back(true) ;
            }
            else
            {
                ip.push_back(false) ;
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            char c ; cin>>c ; 
            if(c=='Y')
            {
                op.push_back(true) ; 
            }
            else
            {
                op.push_back(false) ;
            }
        }
        vector<vector<bool> > vec( n, vector<bool> (n, false));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                vec[i][j] = check(i,j,vec,ip,op) ; 
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(vec[i][j])
                {
                    cout<<"Y" ; 
                }
                else
                {
                    cout<<'N' ; 
                }

            }
            cout<<"\n" ; 
        }
    }
    
}
