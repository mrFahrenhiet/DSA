class Solution {
    private int nosReversePairs = 0;
    
    private void getReversePairs(int[] left, int[] right) {
        int leftIdx = 0, rightIdx = 0;
        
        while(leftIdx < left.length && rightIdx < right.length) {
            if(left[leftIdx] / 2.0 > right[rightIdx]) rightIdx++;
            else {
                nosReversePairs += rightIdx;
                leftIdx++;
            }
        }
        
        while(leftIdx < left.length) {
            nosReversePairs += rightIdx;
            leftIdx++;
        }
        
        return;
        
    }
    
    private int[] merge(int[] left, int[] right) {
        int[] merged = new int[left.length + right.length];
        int leftIdx = 0, rightIdx = 0, mergedIdx = 0;
        
        while(leftIdx < left.length && rightIdx < right.length) {
            if(left[leftIdx] >= right[rightIdx]) merged[mergedIdx++] = right[rightIdx++];
            else merged[mergedIdx++] = left[leftIdx++];
        }
        while(rightIdx < right.length) merged[mergedIdx++] = right[rightIdx++];
        while(leftIdx < left.length) merged[mergedIdx++] = left[leftIdx++];
        
        return merged;
    }
    
    private int[] helper(int[] nums, int start, int end) {
        if(start >= end) return new int[] {nums[start]};
        
        int mid = (2*start + end - start) / 2;
        
        //System.out.println(start + " " + mid + " " + end);
        
        int[] left = helper(nums, start, mid);
        int[] right = helper(nums, mid+1, end);
        
        getReversePairs(left, right);
        
        int[] merged = merge(left, right);
        
        //System.out.println(nosReversePairs);
        
        return merged;
    }
    
    public int reversePairs(int[] nums) {
        int[] temp = helper(nums, 0, nums.length-1);
        
        // for(int t: temp) System.out.print(t + " ");
        // System.out.println();
        
        return nosReversePairs;
    }
}