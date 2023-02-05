class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int m1 = nums[0], m2 = nums[0], c1 = 0, c2 = 0;
        
        for(int i=0;i<nums.length;i++) {
            if(m1 == nums[i]) c1++;
            else if(m2 == nums[i]) c2++;
            else if(c1 <= 0) {
                m1 = nums[i];
                c1 = 1;
            }
            else if(c2 <= 0) {
                m2 = nums[i];
                c2 = 1;
            }
            else {
                c1--;
                c2--;
            }
        }
        
        c1 = 0;
        c2 = 0;
        
        for(int num: nums) {
            if(num == m1) c1++;
            else if(num == m2) c2++;
        }
        
        List<Integer> res = new ArrayList<Integer>();
        
        if(c1 > nums.length / 3) res.add(m1);
        if(c2 > nums.length / 3) res.add(m2);
        
        return res;

    }
}