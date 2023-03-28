class Solution {
    public void sortColors(int[] nums) {
        int[] freq = new int[3];
        
        for(int i=0;i<nums.length;i++) freq[nums[i]]++;
        
        int j = 0;
        for(int i=0;i<3;i++) {
            while(freq[i] > 0) {
                nums[j] = i;
                freq[i]--;
                j++;
            }
        }
        
        return;
    }
}