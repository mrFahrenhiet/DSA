#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > findCumSum(vector<vector<int> > & mat) {
    int m,n;
    n = mat.size();
    m = mat[0].size();
    vector<vector<int> > cumSumMat(n,vector<int>(m,0));
    cumSumMat[0][0] = mat[0][0];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0 && j>0) {
                cumSumMat[0][j] = cumSumMat[0][j-1] + mat[0][j];
            }
            else if(j==0 && i>0) {
                cumSumMat[i][0] = cumSumMat[i-1][0] + mat[i][0];
            }
            else if(i>0 && j>0) {
                cumSumMat[i][j] = (cumSumMat[i-1][j] + cumSumMat[i][j-1]
                 - mat[i-1][j-1] + mat[i][j]);
            }
        }
    }
    return cumSumMat;
}

int sumOfAllSubmatrices(vector<vector<int>> &mat) {
    int m,n;
    n = mat.size();
    m = mat[0].size();
    vector<vector<int> > cumSumMat(n,vector<int>(m,0));
    cumSumMat = findCumSum(mat);
    int s = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int x=i;x<n;x++) {
                for(int y=j;y<n;y++) {
                    if(i>0 && j>0) {
                        s += (cumSumMat[x][y] - cumSumMat[x][j-1] 
                        - cumSumMat[i-1][y] + cumSumMat[i-1][j-1]);
                    }
                    else {
                        s+= cumSumMat[i][j];
                    }
                }
            }
        }
    }
    return s;
}

int main() {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    int n,m;
    cin>>n>>m;
    vector<vector<int> > v(n,vector<int>(m,0));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int no;
            cin>>no;
            v[i][j] = no;
        }
    }
    cout<<sumOfAllSubmatrices(v);
}
