class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[][] dp = new int[n][k+3];
        for(int i=0;i<n;i++) {
            for(int j=0;j<k+3;j++)
                dp[i][j] = Integer.MAX_VALUE;
        }
        
        dp[src][0] = 0;
        
        for(int i=1;i<n;i++) {
            for(int j=0;j<flights.length;j++) {
                int s = flights[j][0];
                int d = flights[j][1];
                int p = flights[j][2];
                
                for(int l=0;l<k+1;l++) {
                    if(dp[s][l] != Integer.MAX_VALUE &&
                       dp[d][l+1] > dp[s][l] + p) {
                        dp[d][l+1] = dp[s][l] + p;
                    }
                }
            }
        }
        int res = Integer.MAX_VALUE;
        
        for(int l=0;l<k+2;l++)
            res = Math.min(res, dp[dst][l]);
        
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}