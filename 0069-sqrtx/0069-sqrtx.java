class Solution {
    public int mySqrt(int x) {
        int low = 1;
        int high = x;
        
        int res = 0;
        
        while(low <= high) {
            int mid = (low + (high - low) / 2);
            if(mid == x / mid) return mid;
            if(mid > x / mid) high = mid - 1;
            else {
                res = mid;
                low = mid + 1;
            }
        }
        
        return res;
    }
}