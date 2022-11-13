class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[][] dp = new int[n][k+2];
        for(int i=0;i<n;i++) {
            for(int j=0;j<k+2;j++)
                dp[i][j] = Integer.MAX_VALUE;
        }
        
        for(int i=0;i<k+2;i++) dp[src][0] = 0;
        
        for(int i=1;i<k+2;i++) {
            for(int j=0;j<flights.length;j++) {
                int s = flights[j][0];
                int d = flights[j][1];
                int p = flights[j][2];
                if(dp[s][i-1] != Integer.MAX_VALUE)
                    dp[d][i] = Math.min(dp[d][i], dp[s][i-1] + p);
            }
        }
        
        int res = Integer.MAX_VALUE;
        for(int i=0;i<k+2;i++) res = Math.min(res, dp[dst][i]);
        
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}