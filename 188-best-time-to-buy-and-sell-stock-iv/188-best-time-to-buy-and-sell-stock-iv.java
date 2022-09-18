class Solution {
    private int helper(int k, int[][][] dp, int[] prices, int i, boolean mode) {
        if(k <= 0 || i >= prices.length) return 0;
        if(dp[i][k][mode ? 1 : 0] != 0) return dp[i][k][mode ? 1 : 0];
        if(mode) {
            int sell = helper(k-1, dp, prices, i+1, !mode) + prices[i];
            int ignore = helper(k, dp, prices, i+1, mode);
            return dp[i][k][mode ? 1 : 0] = Math.max(sell, ignore);
        }
        int buy = helper(k, dp, prices, i+1, !mode) - prices[i];
        int ignore = helper(k, dp, prices, i+1, mode);
        return dp[i][k][mode ? 1 : 0] = Math.max(buy, ignore);
    } 
    public int maxProfit(int k, int[] prices) {
        int[][][] dp = new int[prices.length][k+1][2];
        int res = helper(k, dp, prices, 0, false);
        return res < 0 ? 0 : res;
    }
}