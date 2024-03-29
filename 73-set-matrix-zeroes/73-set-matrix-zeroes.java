class Solution {
    public void setZeroes(int[][] matrix) {
        boolean ZCOL = false, ZROW = false;

        for(int i=0;i<matrix.length;i++) {
            for(int j=0;j<matrix[0].length;j++) {
                if(j == 0 && matrix[i][j] == 0) ZCOL = true;
                if(i == 0 && matrix[i][j] == 0) ZROW = true;
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1;i<matrix.length;i++) {
            for(int j=1;j<matrix[0].length;j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        if(ZCOL) {
            for(int i=0;i<matrix.length;i++) matrix[i][0] = 0;
        }

        if(ZROW) {
            for(int i=0;i<matrix[0].length;i++) matrix[0][i] = 0;
        }
        
        return;
    }
}