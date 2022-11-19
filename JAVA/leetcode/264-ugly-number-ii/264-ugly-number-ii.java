class Solution {
    public int nthUglyNumber(int n) {
        int idx2 = 1, idx3 = 1, idx5 = 1;
        int[] dp = new int[n+1];
        dp[1] = 1;        
        
        for(int i=2;i<=n;i++) {
            int cur = Math.min(2*dp[idx2], Math.min(3*dp[idx3], 5*dp[idx5]));
            dp[i] = cur;
            if(cur == 2 * dp[idx2]) idx2++;
            if(cur == 3 * dp[idx3]) idx3++;
            if(cur == 5 * dp[idx5]) idx5++;
        }
        
        return dp[n];
    }
}