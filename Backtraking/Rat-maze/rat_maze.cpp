#include<bits/stdc++.h>
using namespace std;

class Rat_maze {
private:
    int size;
    vector<vector<int>> board;
public:
    Rat_maze(int n): board(n, vector<int>(n, 0)) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int no;
                cin>>no;
                this->board[i][j] = no;
            }
        }
        this->size = n;
    }
    void maze_util(vector<string>& res, string o, bool visited[50][50], int i, int j) {
        if(i<0 or j<0 or i>=this->size or j>=this->size or this->board[i][j]==0) return;
        if(i==this->size-1 and j==this->size-1) {
            res.push_back(o);
            return;
        }
        visited[i][j] = true;
        // Go Down
        o.push_back('D');
        maze_util(res, o, visited,i+1, j);
        o.pop_back();
        // Go left
        o.push_back('L');
        maze_util(res, o, visited,i, j-1);
        o.pop_back();
        // Go right
        o.push_back('R');
        maze_util(res, o, visited,i, j+1);
        o.pop_back();
        // Go up
        o.push_back('U');
        maze_util(res, o, visited,i-1, j);
        o.pop_back();
        // backtracking step
        visited[i][j] = false;
        return;
    }
    vector<string> all_solutions() {
        vector<string> res;
        string o = "";
        bool visited[this->size+1][this->size+1];
        memset(visited, false, sizeof(visited));
        this->maze_util(res, o, visited, 0, 0);
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
    int n;
    cin>>n;
    Rat_maze r(n);
    vector<string> ans = r.all_solutions();
    for(auto str: ans) cout<<str<<endl;
    return 0;

}