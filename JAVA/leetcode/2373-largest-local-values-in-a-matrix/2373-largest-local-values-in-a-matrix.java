class Solution {
    public int[][] largestLocal(int[][] grid) {
        int row = 0, col = 0;
        int[][] res = new int[grid.length-2][grid.length-2];
        while(row + 2 < grid.length) {
            col = 0;
            while(col + 2 < grid.length) {
                int maxVal = 0;
                for(int i=0;i<3;i++) {
                    for(int j=0;j<3;j++)
                        maxVal = Math.max(maxVal, grid[row + i][col + j]);
                }
                res[row][col] = maxVal;
                col++;
            }
            row++;
        }
        return res;
    }
}