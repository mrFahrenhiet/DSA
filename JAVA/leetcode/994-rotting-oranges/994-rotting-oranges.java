class Solution {
    private int[] dxy = new int[]{0, -1, 0, 1, 0};
    public int orangesRotting(int[][] grid) {
        Queue<int[]> q = new LinkedList<int[]>();
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[0].length;j++) {
                if(grid[i][j] == 2) q.add(new int[]{i, j});
            }
        }
        q.add(new int[]{-1, -1});
        int res = 0;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            if(cur[0] == -1) {
                res++;
                if(!q.isEmpty()) q.add(new int[]{-1, -1});
            }
            for(int i=0;i<dxy.length-1;i++) {
                int row = cur[0] + dxy[i];
                int col = cur[1] + dxy[i+1];
                boolean notOutBounds = row >= 0 && col >=0 && row < grid.length && col < grid[0].length;
                if(notOutBounds && grid[row][col] == 1) {
                    q.add(new int[]{row, col});
                    grid[row][col] = 2;
                }
            }
        }
        
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[0].length;j++) {
                if(grid[i][j] == 1) return -1;
            }
        }
        return res == 0 ? res : res - 1;
    }
}