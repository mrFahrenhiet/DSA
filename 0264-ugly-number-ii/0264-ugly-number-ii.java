class Solution {
    public int nthUglyNumber(int n) {
        int[] dp = new int[n];
        
        dp[0] = 1;
        
        int idx2 = 0, idx3 = 0, idx5 = 0;
        
        for(int i = 1;i < n;i++) {
            dp[i] = Math.min(dp[idx2] * 2, Math.min(dp[idx3] * 3, dp[idx5] * 5));
            if(dp[i] == dp[idx2] * 2) idx2++;
            if(dp[i] == dp[idx3] * 3) idx3++;
            if(dp[i] == dp[idx5] * 5) idx5++;
        }
        
        return dp[n-1];
        
    }
}