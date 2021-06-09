#include <iostream>
#include <vector>

using namespace std;

class N_queen {
private:
    int size, count;
    vector<vector<int>> board;
public:
    N_queen(int n) : board(n, vector<int>(n, 0)) {
        this->size = n;
        this->count = 0;
    }

    int get_count() {
        return this->count;
    }

    bool is_safe(int i, int j) {
        for(int l=0;l<i;l++) {
            if(this->board[l][j]==1) return false;
        }
        int r = i, c = j;
        while(r>=0 and c>=0) {
            if(this->board[r][c]==1) return false;
            r--;
            c--;
        }
        r = i, c = j;
        while(r>=0 and c<this->size) {
            if(this->board[r][c]==1) return false;
            r--;
            c++;
        }
        return true;
    }

    void solver(int i) {
        if(i>=this->size) {
            this->count++;
            return;
        }
        for(int k=0;k<this->size;k++) {
            if(this->is_safe(i, k)) {
                this->board[i][k] = 1;
                this->solver(i+1);
                this->board[i][k] = 0;
            }
        }
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
    N_queen q(n);
    q.solver(0);
    cout<<q.get_count();
    return 0;

}