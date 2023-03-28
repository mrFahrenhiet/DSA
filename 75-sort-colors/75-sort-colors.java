class Solution {
    private void swap(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
        return;
    }
    public void sortColors(int[] nums) {
        int zeros_idx = 0, twos_idx = nums.length-1;
        
        for(int i=0;i<=twos_idx;i++) {
            if(nums[i] == 0) {
                swap(nums, i, zeros_idx);
                zeros_idx++;
            }
            
            if(nums[i] == 2) {
                swap(nums, i, twos_idx);
                twos_idx--;
                i--;
            }
            
            
        }
    }
}