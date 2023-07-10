class Solution {
    public int mySqrt(int x) {
        int low = 1;
        int high = x;
        
        int mid = 0;
        
        while(low <= high) {
            mid = (low + (high - low) / 2);

            if(mid > x / mid) high = mid - 1;
            else low = mid + 1;
        }
        
        return low - 1;
    }
}