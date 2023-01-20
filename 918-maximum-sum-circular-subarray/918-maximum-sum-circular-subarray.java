class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int res_str = Integer.MIN_VALUE, res_cir = Integer.MAX_VALUE;
        int temp_str = 0, temp_cir = 0, tol_s = 0;
        
        for(int i=0;i<nums.length;i++) {
            tol_s += nums[i];
            temp_cir += nums[i];
            res_cir = Math.min(temp_cir, res_cir);
            if(temp_cir > 0) temp_cir = 0;
        }
        
        res_cir = res_cir == tol_s ? tol_s : tol_s - res_cir;
        
        for(int i=0;i<nums.length;i++) {
            temp_str += nums[i];
            res_str = Math.max(res_str, temp_str);
            if(temp_str < 0) temp_str = 0;
        }
        
        return Math.max(res_cir, res_str);
    }
}