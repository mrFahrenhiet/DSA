class Solution {
    private void swap(int[][] matrix, int row1, int col1, int row2, int col2) {
        int temp = matrix[row1][col1];
        matrix[row1][col1] = matrix[row2][col2];
        matrix[row2][col2] = temp;
        return;
    } 
    public void rotate(int[][] matrix) {
        for(int i=0;i<matrix.length;i++) {
            for(int j=0;j<=i;j++) {
                swap(matrix, i, j, j, i);
            }
        }
        
        for(int i=0;i<matrix.length;i++) {
            for(int j=0;j<matrix[0].length/2;j++) {
                swap(matrix, i, j, i, matrix[0].length-1-j);
            }
        }
    }
}