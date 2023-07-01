class Solution {
    private boolean isRightMove(char[][] board, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] != '.' && board[i][col] == c) return false;
            if(board[row][i] != '.' && board[row][i] == c) return false;
            if(board[3 * (row / 3) + i / 3][ 3 * (col / 3) + i % 3] != '.' && 
board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;        
    }
    
    private boolean helper(char[][] board, int i, int j) {
        if(j >= board[0].length) {
            i++;
            j = 0;
        }
        
        if(i >= board.length) return true;
        if(board[i][j] != '.') return helper(board, i, j+1);
        
        for(int k=1;k<=9;k++) {
            char x = (char)(k + (int)'0');
            if(isRightMove(board, i, j, x)) {
                board[i][j] = x;
                if(helper(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }     
        return false;
    }
    
    public void solveSudoku(char[][] board) {
        boolean x = helper(board, 0, 0);
        return;
    }
}