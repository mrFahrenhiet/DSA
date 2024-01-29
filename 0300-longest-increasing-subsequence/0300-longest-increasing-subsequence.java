class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        dp[0] = 1;
        
        for(int i=1;i<nums.length;i++) {
            int max_left = 0;
            dp[i] = 1;
            
            for(int j=i; j>=0; j--) {
                if(nums[j] < nums[i]) max_left = Math.max(dp[j], max_left);
            }
            
            dp[i] += max_left;
        }
        
        int res = 0;
        
        for(int i=0;i<nums.length;i++) {
            res = Math.max(res, dp[i]);
        }
        
        return res;
    }
}