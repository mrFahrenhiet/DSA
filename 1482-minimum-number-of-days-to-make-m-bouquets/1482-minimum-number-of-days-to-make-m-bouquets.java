class Solution {
    private boolean isDaysEnough(int[] bloomDay, int m, int k, int days) {
        int flowers = 0;
        
        for(int i = 0; i < bloomDay.length; i++) {
            if(bloomDay[i] <= days) flowers++;
            else flowers = 0;
            
            if(flowers >= k) {
                m--;
                flowers = 0;
            }            
        }
        
        return m <= 0;
    }
    
    public int minDays(int[] bloomDay, int m, int k) {
        if(m > bloomDay.length / k) return -1;
            
        int low = 1, high = 0;
        for(int bloom: bloomDay) high = Math.max(high, bloom);
                
        while(low < high) {
            int mid = (low + (high - low) / 2);
            if(isDaysEnough(bloomDay, m, k, mid))
                high = mid;
            else
                low = mid + 1;
        }
                        
        return low;
    }
}