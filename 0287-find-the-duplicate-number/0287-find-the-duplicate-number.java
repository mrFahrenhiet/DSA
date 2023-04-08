class Solution {
    private void swap(int[] nums, int i1, int i2) {
        int temp = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = temp;
        return;
    }
    
    public int findDuplicate(int[] nums) {
        for(int i=0;i<nums.length;i++) {
            while(nums[i] != i + 1 && nums[nums[i]-1] != nums[i])
                  swap(nums, i, nums[i] - 1);
            
            if(nums[i] != i + 1) return nums[i];
        }
        
        return -1;
    }
}