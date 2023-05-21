class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        
        Arrays.sort(nums);
        
        for(int i=0;i<nums.length;i++) {
            List<Integer> temp = new ArrayList<Integer>();
            
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            temp.add(nums[i]);
            
            int target = -1 * nums[i], st = i + 1, en = nums.length - 1;
                        
            while(st < en) {
                while(st < en && st > i+1 && nums[st] == nums[st-1]) st++;
                if(st >= en) break;
                
                if(nums[st] + nums[en] == target) {
                    temp.add(nums[st]);
                    temp.add(nums[en]);
                    
                    res.add(new ArrayList<Integer>(temp));
                    
                    temp.remove(temp.size() - 1);
                    temp.remove(temp.size() - 1);
                    
                    st++;
                    en--;
                }
                else if(nums[st] + nums[en] > target) en--;
                else st++;
            }
            
            temp.remove(temp.size() - 1);
        }
        
        return res;
    }
}