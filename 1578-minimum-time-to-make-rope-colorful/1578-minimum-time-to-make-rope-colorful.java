class Solution {
    public int minCost(String colors, int[] neededTime) {
        int res = 0;
        for(int i=1;i<colors.length();i++) {
            if(colors.charAt(i) == colors.charAt(i-1)) {
                if(neededTime[i] < neededTime[i-1]) {
                    res += neededTime[i];
                    neededTime[i] = neededTime[i-1];
                }
                else res += neededTime[i-1];
            }
        }
        
        return res;
    }
}