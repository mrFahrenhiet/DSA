class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> presence = new HashSet<Integer>();
        
        int res = 0;
        
        for(int num: nums)
            presence.add(num);
        
        for(int i=0;i<nums.length;i++) {
            if(!presence.contains(nums[i])) continue;
            int l = nums[i] - 1, r = nums[i] + 1, seq = 1;
            while(presence.contains(l) && presence.contains(r)) {
                presence.remove(l--);
                presence.remove(r++);
                                
                seq += 2;
            }
            while(presence.contains(l)) {
                presence.remove(l--);
                seq++;
            }
            while(presence.contains(r)) {
                presence.remove(r++);
                seq++;
            }
            
            res = Math.max(res, seq);
        }
        
        return res;
    }
}