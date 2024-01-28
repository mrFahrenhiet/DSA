class Solution {
    public int maxProduct(int[] nums) {
        int max_ahead = Integer.MIN_VALUE, max_behind = Integer.MIN_VALUE, curr = 1;
        
        for(int i=0;i<nums.length;i++) {
            curr *= nums[i];
            max_ahead = Math.max(curr, max_ahead);
            
            if(curr == 0) {
                curr = 1;
            }
        }
        
        curr = 1;
        
                
        for(int i = nums.length - 1;i >= 0;i--) {
            curr *= nums[i];
            max_behind = Math.max(curr, max_behind);
            
            if(curr == 0) {
                curr = 1;
            }
        }
        
        return Math.max(max_ahead, max_behind);
    }
}