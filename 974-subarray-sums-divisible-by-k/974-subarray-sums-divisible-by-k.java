class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int[] cumSum = new int[nums.length];
        HashMap<Integer, Integer> freqM = new HashMap<>();
        int res = 0;
        
        cumSum[0] = nums[0];
        freqM.put(0, 1);
        
        for(int i=1;i<nums.length;i++)
            cumSum[i] = cumSum[i-1] + nums[i];
        
        for(int i=0;i<nums.length;i++) {
            int rem = cumSum[i] % k;
            if(rem < 0) rem += k;
            res += freqM.getOrDefault(rem, 0);
            freqM.put(rem, freqM.getOrDefault(rem, 0) + 1);
        }
        
        return res;
    }
}