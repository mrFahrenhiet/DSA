#include <iostream>
#include <vector>
#define INT_MAX 99999
using namespace std;

int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};

int VISITED_ALL = (1<<4)-1;
vector<vector<int> > dp(1000,vector<int>(100,-1));
int tsp(int mask, int pos) {
    if(mask==VISITED_ALL) {
        return dist[pos][0];
    }
    if(dp[mask][pos]!=-1) {
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    for(int city=0;city<4;city++) {
        if((mask&(1<<city))==0){
            int x = dist[pos][city] + tsp(mask|(1<<city),city);
            ans = min(ans,x);
        }
    }
    return dp[mask][pos] = ans;
}


int main() {
    int mask = 1;
    int pos = 0;
    cout<<tsp(mask,pos);
    
}
