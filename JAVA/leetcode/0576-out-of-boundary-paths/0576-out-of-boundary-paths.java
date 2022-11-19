class Solution {
    private int MOD = 1_000_000_007;
    private int[] dxy = new int[]{0, -1, 0, 1, 0};
    private int helper(int m, int n, int maxMove, int r, int c, Integer[][][] dp) {
        if(maxMove < 0) return 0;
        if(r < 0 || r >= m || c < 0 || c >= n) return 1;
        if(dp[maxMove][r][c] != null) return dp[maxMove][r][c];
        int res = 0;
        for(int i=0;i<dxy.length-1;i++) {
            if(maxMove > 0)
                res = (res + helper(m, n, maxMove-1, r+dxy[i], c+dxy[i+1], dp)) % MOD;
        }
        return dp[maxMove][r][c] = res;
    }
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        Integer[][][] dp = new Integer[maxMove+1][m][n];
        return helper(m, n, maxMove, startRow, startColumn, dp);
    }
}