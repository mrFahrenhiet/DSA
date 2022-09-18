class Solution {
    private int helper(int[][] dp, int[] prices, int i, int fees, boolean mode) {
        if(i >= prices.length) return 0;
        if(dp[i][mode ? 1 : 0] != 0) return dp[i][mode ? 1 : 0];
        if(mode) {
            int sell = helper(dp, prices, i+1, fees, !mode) + prices[i] - fees;
            int ignore = helper(dp, prices, i+1, fees, mode);
            return dp[i][mode ? 1 : 0] = Math.max(sell, ignore);
        }
        int buy = helper(dp, prices, i+1, fees, !mode) - prices[i];
        int ignore = helper(dp, prices, i+1, fees, mode);
        return dp[i][mode ? 1 : 0] = Math.max(buy, ignore);
    } 
    public int maxProfit(int[] prices, int fees) {
        int[][] dp = new int[prices.length][2];
        int res = helper(dp, prices, 0, fees, false);
        return res < 0 ? 0 : res;
    }
}