class Solution {
    private void reverse(int[] arr, int start, int end) {
        while(start < end) {
            swap(arr, start++, end--);
        }
        return;
    }
    
    private void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
        return;
    } 
    
    public void nextPermutation(int[] nums) {
        int prefixIdx = -1;
        int mkePrefixGreater = nums.length-1;
        
        for(int i=nums.length-2;i>=0;i--) {
            if(nums[i+1] > nums[i]) {
                prefixIdx = i;
                break;
            }
        }
        
        if(prefixIdx == -1) {
            Arrays.sort(nums);
            return;
        }
        
        for(int i=nums.length-1;i>=prefixIdx;i--) {
            if(nums[i] > nums[prefixIdx]) {
                mkePrefixGreater = i;
                break;
            }
        }
        
        swap(nums, prefixIdx, mkePrefixGreater);
        
        reverse(nums, prefixIdx + 1, nums.length-1);
        
        return;
        
    }
}