class Solution {
    public boolean isSafe(char[][] mat, int row, int col) {
        for(int i=0;i<row;i++) 
            if(mat[i][col] == 'Q') return false;
        
        for(int j=0;j<col;j++)
            if(mat[row][j] == 'Q') return false;
        
        int i = row - 1, j = col - 1;
        while(i >= 0 && j >= 0) {
            if(mat[i][j] == 'Q') return false;
            i--;
            j--;
        }
        
        i = row - 1;
        j = col + 1;
        while(i >= 0 && j < mat[0].length) {
            if(mat[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    public void add_sol(List<List<String>> res, char[][] board) {
        String temp;
        List<String> sol = new ArrayList<String>();
        for(int i=0;i<board.length;i++) {
            temp = new String(board[i]);
            sol.add(temp);
        }
        res.add(sol);
        return;
    }
    public boolean helper(char[][] board, List<List<String>> res, int r) {
        if(r >= board.length) {
            add_sol(res, board);
            return true;
        }
        for(int c=0;c<board[0].length;c++) {
            if(isSafe(board, r, c)) {
                board[r][c] = 'Q';
                boolean x = helper(board, res, r+1);
                board[r][c] = '.';
            }
        }
        return false;
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        char[][] board = new char[n][n];
        StringBuilder mat_row = new StringBuilder();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) board[i][j] = '.';
        }
        boolean x = helper(board, res, 0);
        return res;
    }
}