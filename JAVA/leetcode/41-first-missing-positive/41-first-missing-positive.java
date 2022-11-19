class Solution {
    private void swap(int[] arr, int x, int y) {
        int temp = arr[x];
        arr[x] = arr[y];
        arr[y] = temp;
        return;
    }
    public int firstMissingPositive(int[] nums) {
        for(int i=0;i<nums.length;i++) {
            while(nums[i] > 0 && nums[i] <= nums.length && nums[nums[i]-1] != nums[i])
                swap(nums, i, nums[i] - 1);
        }
        
        for(int i=0;i<nums.length;i++) {
            if(nums[i] != i + 1) return i + 1; 
        }
        return nums.length+1;
    }
}