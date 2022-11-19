class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int[] freq = new int[k+1];
        int res = 0, sum = 0;
        freq[0] = 1;
        for(int i=0;i<nums.length;i++) {
            sum = (sum + nums[i]) % k;
            if(sum < 0) sum += k;
            res += freq[sum];
            freq[sum]++;
        }
        return res;
    }
}