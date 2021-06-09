#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class Knight_move {
private:
    vector<vector<int>> board;
    int size;
    int x_move[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y_move[8] = {1, 2, 2, 1, -1, -2, -2, -1};
public:
    Knight_move(int n): board(n, vector<int>(n, -1)) {
        this->size = n;
    }
    bool is_safe(int i, int j) {
        return (i>=0 and j>=0 and i<this->size and j<this->size and
        this->board[i][j]==-1);
    }
    bool moves(int i, int j, int count) {
        if(count==(this->size)*(this->size)) return true;
        for(int k=0;k<8;k++) {
            int ni = i+this->x_move[k];
            int nj = j+this->y_move[k];
            if(this->is_safe(ni, nj)) {
                this->board[ni][nj] = count;
                if(this->moves(ni, nj, count+1)) return true;
                else this->board[ni][nj] = -1;
            }
        }
        return false;
    }
    void print() {
        for(int i=0;i<this->size;i++) {
            for(int j=0;j<this->size;j++) {
                cout<<this->board[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    void main_fn() {
        this->board[0][0] = 0;
        bool x = this->moves(0, 0, 1);
        if(x) this->print();
        else cout<<"No Solution"<<endl;
        return;
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
    Knight_move km(n);
    km.main_fn();
    return 0;

}