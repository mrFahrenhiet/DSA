class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> numsSet = new HashSet<Integer>();
        for(int i=0;i<nums.length;i++) {
            if(!numsSet.contains(nums[i]))
                numsSet.add(nums[i]);
        }
        
        int res = 0;
        for(int i=0;i<nums.length;i++) {
            int left = nums[i]-1, right = nums[i]+1, temp = 1;
            while(numsSet.contains(left)) {
                numsSet.remove(left);
                left--;
                temp++;
            }
            while(numsSet.contains(right)) {
                numsSet.remove(right);
                right++;
                temp++;
            }
            
            res = Math.max(res, temp);
        }
        
        return res;
    }
}