class Solution {
    private boolean isEnoughCap(int[] weights, int cap, int days) {
        int cumWeight = 0;
        for(int weight: weights) {            
            cumWeight += weight;
            
            if(cumWeight > cap) {
                days--;
                cumWeight = weight;
            }
            
            if(days <= 0) return false;
        }
        
        return true;
    }
    
    public int shipWithinDays(int[] weights, int days) {
        int low = 0;
        int high = 0;
        
        for(int weight: weights) {
            low = Math.max(low, weight);
            high += weight;
        }
                        
        while(low <= high) {
            int mid = (low + (high - low) / 2);
            if(isEnoughCap(weights, mid, days)) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
}