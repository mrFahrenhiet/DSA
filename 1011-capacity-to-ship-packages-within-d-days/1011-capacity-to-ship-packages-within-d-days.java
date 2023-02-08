class Solution {
    private boolean verify(int[] weights, int days, int capacity) {
        int curLoad = 0;        
        for(int i=0;i<weights.length;i++) { 
            if(capacity < weights[i]) return false;
            
            if(curLoad + weights[i] > capacity) {
                days--;
                curLoad = 0;   
            }
            
            if(days <= 0) return false;
            
            curLoad += weights[i];
        }
                
        return true;
    }
    
    public int shipWithinDays(int[] weights, int days) {        
        int maxCap = 0, minCap = 0;
        
        for(int weight: weights) maxCap += weight;
        
        int res = maxCap;
        
        while(maxCap >= minCap) {
            int midCap = minCap + (maxCap - minCap) / 2;
            if(verify(weights, days, midCap)) {
                res = Math.min(res, midCap);
                maxCap = midCap - 1;
            }
            else
                minCap = midCap + 1;
        }
        
        return res;
    }
}