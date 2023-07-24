class Solution {
    private boolean isDaysEnough(int[] bloomDay, int m, int k, int days) {
        Queue<Integer> q = new LinkedList<Integer>();
        
        for(int i = 0; i < bloomDay.length; i++) {
            if(bloomDay[i] <= days) q.add(i);
            else {
                while(q.size() > 0) q.remove();
            }
            
            if(q.size() >= k) {
                m--;
                while(q.size() > 0) q.remove();
            }
            
            if(m <= 0) return true;
        }
        
        return m <= 0;
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int low = 1, high = 0;
        for(int bloom: bloomDay) high = Math.max(high, bloom);
                
        while(low < high) {
            int mid = (low + (high - low) / 2);
            if(isDaysEnough(bloomDay, m, k, mid))
                high = mid;
            else
                low = mid + 1;
        }
        
        boolean lastRes = isDaysEnough(bloomDay, m, k, low);
                
        return lastRes ? low: -1;
    }
}