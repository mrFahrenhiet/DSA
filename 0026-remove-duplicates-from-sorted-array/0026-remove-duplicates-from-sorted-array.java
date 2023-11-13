class Solution {
    public int removeDuplicates(int[] nums) {
        int curUniqueEl = nums[0], curIdx = 1;
        
        for(int i=1;i<nums.length;i++) {
            if(curUniqueEl != nums[i]) {
                nums[curIdx] = nums[i];
                curUniqueEl = nums[i];
                curIdx++;
            }
        }
        
        return curIdx;
    }
}