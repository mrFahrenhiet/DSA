class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);
        int beg = 0, end = nums.length - 1;
        while(beg < nums.length && nums[beg] == sortedNums[beg]) beg++;
        while(end >= beg && nums[end] == sortedNums[end]) end--;
        return end - beg + 1;
    }
}